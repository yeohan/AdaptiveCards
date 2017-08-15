"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var InputControl = (function () {
    function InputControl() {
    }
    InputControl.prototype.validateRootElement = function (rootElement) {
        // Do nothing - all root element types are valid.
    };
    InputControl.prototype.keyDown = function (e) {
        // Do nothing in base implementation
    };
    Object.defineProperty(InputControl.prototype, "rootElement", {
        get: function () {
            return this._rootElement;
        },
        enumerable: true,
        configurable: true
    });
    InputControl.prototype.attach = function (rootElement) {
        var _this = this;
        this.validateRootElement(rootElement);
        this._rootElement = rootElement;
        this._rootElement.onkeydown = function (e) { _this.keyDown(e); };
    };
    return InputControl;
}());
exports.InputControl = InputControl;
//# sourceMappingURL=inputcontrol.js.map