"use strict";
var __extends = (this && this.__extends) || (function () {
    var extendStatics = Object.setPrototypeOf ||
        ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
        function (d, b) { for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p]; };
    return function (d, b) {
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
var Constants = require("./constants");
var Utils = require("./utils");
var inputcontrol_1 = require("./inputcontrol");
var PopupControl = (function () {
    function PopupControl() {
    }
    PopupControl.prototype.close = function () {
        if (this.onClose) {
            this.onClose(this);
        }
    };
    PopupControl.prototype.keyDown = function (e) {
        switch (e.keyCode) {
            case Constants.KEY_ESCAPE:
                this.close();
                break;
        }
    };
    PopupControl.prototype.render = function (rootElementBounds) {
        var _this = this;
        this._popupElement = document.createElement("div");
        this._popupElement.tabIndex = 0;
        this._popupElement.className = "ms-ctrl ms-ctrl-popup-container";
        this._popupElement.onkeydown = function (e) {
            _this.keyDown(e);
            return !e.cancelBubble;
        };
        this._popupElement.appendChild(this.renderContent());
        return this._popupElement;
    };
    PopupControl.prototype.focus = function () {
        if (this._popupElement) {
            this._popupElement.firstElementChild.focus();
        }
    };
    return PopupControl;
}());
exports.PopupControl = PopupControl;
var InputWithPopup = (function (_super) {
    __extends(InputWithPopup, _super);
    function InputWithPopup() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    InputWithPopup.prototype.keyDown = function (e) {
        switch (e.keyCode) {
            case Constants.KEY_ENTER:
                this.popup();
                break;
        }
    };
    InputWithPopup.prototype.updateLabel = function () {
        if (this._labelElement) {
            if (this._value) {
                this._labelElement.innerHTML = this.getValueAsString();
                this._labelElement.classList.remove("placeholder");
            }
            else {
                this._labelElement.innerText = this._placeholderText ? this._placeholderText : "";
                this._labelElement.classList.add("placeholder");
            }
        }
    };
    Object.defineProperty(InputWithPopup.prototype, "popupControl", {
        get: function () {
            return this._popupControl;
        },
        enumerable: true,
        configurable: true
    });
    InputWithPopup.prototype.getButtonIconCssClassName = function () {
        return "ms-icon-chevronDown";
    };
    InputWithPopup.prototype.getValueAsString = function () {
        return this._value.toString();
    };
    InputWithPopup.prototype.attach = function (rootElement) {
        var _this = this;
        _super.prototype.attach.call(this, rootElement);
        rootElement.tabIndex = 0;
        rootElement.className = this.getCssClassName();
        window.addEventListener("resize", function (e) { _this.closePopup(); });
        this.rootElement.onclick = function (e) {
            if (_this._isOpen) {
                _this.closePopup();
            }
            else {
                _this.popup();
            }
        };
        this._placeholderText = this.rootElement.attributes.getNamedItem("placeholder").value;
        this._labelElement = document.createElement("span");
        this._labelElement.className = "ms-ctrl ms-dropdown-label";
        this._dropDownButtonElement = document.createElement("i");
        this._dropDownButtonElement.className = "ms-icon ms-ctrl-dropdown-button " + this.getButtonIconCssClassName();
        ;
        this.rootElement.appendChild(this._labelElement);
        this.rootElement.appendChild(this._dropDownButtonElement);
        this.updateLabel();
    };
    InputWithPopup.prototype.popup = function () {
        var _this = this;
        if (!this._isOpen) {
            this._overlayElement = document.createElement("div");
            this._overlayElement.className = "ms-ctrl-overlay";
            this._overlayElement.tabIndex = 0;
            this._overlayElement.style.width = document.documentElement.scrollWidth + "px";
            this._overlayElement.style.height = document.documentElement.scrollHeight + "px";
            this._overlayElement.onfocus = function (e) { _this.closePopup(); };
            document.body.appendChild(this._overlayElement);
            this._popupControl = this.createPopupControl();
            this._popupControl.onClose = function (sender) {
                _this.closePopup();
                _this.rootElement.focus();
            };
            var rootElementBounds = this.rootElement.getBoundingClientRect();
            this._popupControlElement = this._popupControl.render(rootElementBounds);
            this._popupControlElement.classList.remove("ms-ctrl-slide", "ms-ctrl-slideLeftToRight", "ms-ctrl-slideRightToLeft", "ms-ctrl-slideTopToBottom", "ms-ctrl-slideRightToLeft");
            this._overlayElement.appendChild(this._popupControlElement);
            var popupElementBounds = this._popupControlElement.getBoundingClientRect();
            var availableSpaceBelow = window.innerHeight - rootElementBounds.bottom;
            var availableSpaceAbove = rootElementBounds.top;
            var left = rootElementBounds.left + Utils.getScrollX();
            var top;
            if (availableSpaceAbove < popupElementBounds.height && availableSpaceBelow < popupElementBounds.height) {
                // Not enough space above or below root element
                var actualPopupHeight = Math.min(popupElementBounds.height, window.innerHeight);
                this._popupControlElement.style.maxHeight = actualPopupHeight + "px";
                if (actualPopupHeight < popupElementBounds.height) {
                    top = Utils.getScrollY();
                }
                else {
                    top = Utils.getScrollY() + rootElementBounds.top + (rootElementBounds.height - actualPopupHeight) / 2;
                }
                var availableSpaceRight = window.innerWidth - rootElementBounds.right;
                var availableSpaceLeft = rootElementBounds.left;
                if (availableSpaceLeft < popupElementBounds.width && availableSpaceRight < popupElementBounds.width) {
                    // Not enough space left or right of root element
                    var actualPopupWidth = Math.min(popupElementBounds.width, window.innerWidth);
                    this._popupControlElement.style.maxWidth = actualPopupWidth + "px";
                    if (actualPopupWidth < popupElementBounds.width) {
                        left = Utils.getScrollX();
                    }
                    else {
                        left = Utils.getScrollX() + rootElementBounds.left + (rootElementBounds.width - actualPopupWidth) / 2;
                    }
                }
                else {
                    // Enough space on the left or right of the root element
                    if (availableSpaceRight >= popupElementBounds.width) {
                        left = Utils.getScrollX() + rootElementBounds.right;
                        this._popupControlElement.classList.add("ms-ctrl-slide", "ms-ctrl-slideLeftToRight");
                    }
                    else {
                        left = Utils.getScrollX() + rootElementBounds.left - popupElementBounds.width;
                        this._popupControlElement.classList.add("ms-ctrl-slide", "ms-ctrl-slideRightToLeft");
                    }
                }
            }
            else {
                // Enough space above or below root element
                if (availableSpaceBelow >= popupElementBounds.height) {
                    top = Utils.getScrollY() + rootElementBounds.bottom;
                    this._popupControlElement.classList.add("ms-ctrl-slide", "ms-ctrl-slideTopToBottom");
                }
                else {
                    top = Utils.getScrollY() + rootElementBounds.top - popupElementBounds.height;
                    this._popupControlElement.classList.add("ms-ctrl-slide", "ms-ctrl-slideBottomToTop");
                }
            }
            this._popupControlElement.style.left = left + "px";
            this._popupControlElement.style.top = top + "px";
            this._popupControlElement.focus();
            this._isOpen = true;
        }
    };
    InputWithPopup.prototype.closePopup = function () {
        if (this._isOpen) {
            document.body.removeChild(this._overlayElement);
            this._isOpen = false;
        }
    };
    Object.defineProperty(InputWithPopup.prototype, "isOpen", {
        get: function () {
            return this._isOpen;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(InputWithPopup.prototype, "placeholderText", {
        get: function () {
            return this._placeholderText;
        },
        set: function (value) {
            this._placeholderText = value;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(InputWithPopup.prototype, "value", {
        get: function () {
            return this._value;
        },
        set: function (newValue) {
            this._value = newValue;
            this.updateLabel();
        },
        enumerable: true,
        configurable: true
    });
    return InputWithPopup;
}(inputcontrol_1.InputControl));
exports.InputWithPopup = InputWithPopup;
//# sourceMappingURL=inputwithpopup.js.map