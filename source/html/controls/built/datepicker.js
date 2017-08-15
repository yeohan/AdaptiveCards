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
var inputwithpopup_1 = require("./inputwithpopup");
var calendar_1 = require("./calendar");
var CalendarPopupControl = (function (_super) {
    __extends(CalendarPopupControl, _super);
    function CalendarPopupControl(owner) {
        var _this = _super.call(this) || this;
        _this._owner = owner;
        return _this;
    }
    CalendarPopupControl.prototype.renderContent = function () {
        var _this = this;
        var element = document.createElement("div");
        element.className = "ms-ctrl ms-calendarPopup";
        this._calendar = new calendar_1.Calendar();
        this._calendar.date = this._owner.value;
        this._calendar.onDateChanged = function (c) {
            _this._owner.value = c.date;
            _this.close();
        };
        this._calendar.attach(element);
        return element;
    };
    CalendarPopupControl.prototype.focus = function () {
        if (this._calendar) {
            this._calendar.focus();
        }
    };
    return CalendarPopupControl;
}(inputwithpopup_1.PopupControl));
exports.CalendarPopupControl = CalendarPopupControl;
var DatePicker = (function (_super) {
    __extends(DatePicker, _super);
    function DatePicker() {
        return _super !== null && _super.apply(this, arguments) || this;
    }
    DatePicker.prototype.validateRootElement = function (rootElement) {
        if (!(rootElement instanceof HTMLDivElement)) {
            throw new Error("DatePicker requires a DIV element as its root.");
        }
    };
    DatePicker.prototype.createPopupControl = function () {
        return new CalendarPopupControl(this);
    };
    DatePicker.prototype.getValueAsString = function () {
        return this.value.toLocaleDateString();
    };
    DatePicker.prototype.getCssClassName = function () {
        return "ms-ctrl ms-ctrl-datePicker";
    };
    DatePicker.prototype.getButtonIconCssClassName = function () {
        return "ms-icon-calendar";
    };
    DatePicker.prototype.popup = function () {
        _super.prototype.popup.call(this);
        if (this.isOpen) {
            this.popupControl.focus();
        }
    };
    return DatePicker;
}(inputwithpopup_1.InputWithPopup));
exports.DatePicker = DatePicker;
//# sourceMappingURL=datepicker.js.map