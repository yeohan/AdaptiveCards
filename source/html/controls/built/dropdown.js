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
var collection_1 = require("./collection");
var inputwithpopup_1 = require("./inputwithpopup");
var DropDownItem = (function () {
    function DropDownItem(key, value) {
        this.key = key;
        this._value = value;
    }
    DropDownItem.prototype.click = function () {
        if (this.onClick) {
            this.onClick(this);
        }
    };
    DropDownItem.prototype.toString = function () {
        return this.value;
    };
    DropDownItem.prototype.render = function () {
        var _this = this;
        if (!this._element) {
            this._element = document.createElement("span");
            this._element.className = "ms-ctrl ms-ctrl-dropdown-item";
            this._element.innerText = this.value;
            this._element.onclick = function (e) { _this.click(); };
        }
        return this._element;
    };
    Object.defineProperty(DropDownItem.prototype, "value", {
        get: function () {
            return this._value;
        },
        set: function (newValue) {
            this._value = newValue;
            if (this._element) {
                this._element.innerText = newValue;
            }
        },
        enumerable: true,
        configurable: true
    });
    return DropDownItem;
}());
exports.DropDownItem = DropDownItem;
var DropDownPopupControl = (function (_super) {
    __extends(DropDownPopupControl, _super);
    function DropDownPopupControl(owner) {
        var _this = _super.call(this) || this;
        _this._renderedItems = [];
        _this._selectedIndex = -1;
        _this._owner = owner;
        return _this;
    }
    DropDownPopupControl.prototype.renderContent = function () {
        var element = document.createElement("div");
        element.className = "ms-ctrl ms-popup";
        var selectedIndex = this._owner.selectedIndex;
        for (var i = 0; i < this._owner.items.length; i++) {
            var renderedItem = this._owner.items.get(i).render();
            renderedItem.tabIndex = 0;
            element.appendChild(renderedItem);
            if (i == selectedIndex) {
                renderedItem.focus();
            }
            this._renderedItems.push(renderedItem);
        }
        return element;
    };
    DropDownPopupControl.prototype.keyDown = function (e) {
        _super.prototype.keyDown.call(this, e);
        var selectedItemIndex = this._selectedIndex;
        switch (e.keyCode) {
            case Constants.KEY_TAB:
                this.close();
                break;
            case Constants.KEY_ENTER:
                if (this.selectedIndex >= 0) {
                    this._owner.selectedIndex = this.selectedIndex;
                    this.close();
                }
                break;
            case Constants.KEY_UP:
                if (selectedItemIndex <= 0) {
                    selectedItemIndex = this._renderedItems.length - 1;
                }
                else {
                    selectedItemIndex--;
                    if (selectedItemIndex < 0) {
                        selectedItemIndex = this._renderedItems.length - 1;
                    }
                }
                this.selectedIndex = selectedItemIndex;
                e.cancelBubble = true;
                break;
            case Constants.KEY_DOWN:
                if (selectedItemIndex < 0) {
                    selectedItemIndex = 0;
                }
                else {
                    selectedItemIndex++;
                    if (selectedItemIndex >= this._renderedItems.length) {
                        selectedItemIndex = 0;
                    }
                }
                this.selectedIndex = selectedItemIndex;
                e.cancelBubble = true;
                break;
        }
    };
    DropDownPopupControl.prototype.render = function (rootElementBounds) {
        var renderedElement = _super.prototype.render.call(this, rootElementBounds);
        renderedElement.style.minWidth = (rootElementBounds.width / 2) + "px";
        renderedElement.style.maxWidth = rootElementBounds.width + "px";
        return renderedElement;
    };
    Object.defineProperty(DropDownPopupControl.prototype, "selectedIndex", {
        get: function () {
            return this._selectedIndex;
        },
        set: function (index) {
            if (index >= 0 && index < this._renderedItems.length) {
                this._renderedItems[index].focus();
                this._selectedIndex = index;
            }
        },
        enumerable: true,
        configurable: true
    });
    return DropDownPopupControl;
}(inputwithpopup_1.PopupControl));
exports.DropDownPopupControl = DropDownPopupControl;
var DropDown = (function (_super) {
    __extends(DropDown, _super);
    function DropDown() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    DropDown.prototype.itemClicked = function (item) {
        this.selectedItem = item;
        this.closePopup();
        this.rootElement.focus();
    };
    DropDown.prototype.validateRootElement = function (rootElement) {
        if (!(rootElement instanceof HTMLDivElement)) {
            throw new Error("DropDown requires a DIV element as its root.");
        }
    };
    DropDown.prototype.createPopupControl = function () {
        return new DropDownPopupControl(this);
    };
    DropDown.prototype.getCssClassName = function () {
        return "ms-ctrl ms-ctrl-dropdown";
    };
    DropDown.prototype.attach = function (rootElement) {
        var _this = this;
        _super.prototype.attach.call(this, rootElement);
        this._items = new collection_1.Collection();
        this._items.onItemAdded = function (item) { item.onClick = function (clickedItem) { _this.itemClicked(clickedItem); }; };
        this._items.onItemRemoved = function (item) { item.onClick = null; };
        for (var i = 0; i < this.rootElement.children.length; i++) {
            var childElement = this.rootElement.children[i];
            if (childElement.tagName.toLowerCase() == "ms-dropdown-item") {
                var item = new DropDownItem(childElement.attributes.getNamedItem("key").value, childElement.attributes.getNamedItem("value").value);
                this._items.add(item);
            }
        }
    };
    DropDown.prototype.popup = function () {
        _super.prototype.popup.call(this);
        this.popupControl.selectedIndex = this.selectedIndex;
    };
    Object.defineProperty(DropDown.prototype, "items", {
        get: function () {
            return this._items;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(DropDown.prototype, "selectedItem", {
        get: function () {
            return this.value;
        },
        set: function (newValue) {
            this.value = newValue;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(DropDown.prototype, "selectedIndex", {
        get: function () {
            return this.items.indexOf(this.value);
        },
        set: function (index) {
            if (index >= 0 && this.items.length > index) {
                this.selectedItem = this.items.get(index);
            }
        },
        enumerable: true,
        configurable: true
    });
    return DropDown;
}(inputwithpopup_1.InputWithPopup));
exports.DropDown = DropDown;
//# sourceMappingURL=dropdown.js.map