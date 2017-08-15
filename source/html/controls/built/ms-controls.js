"use strict";
function __export(m) {
    for (var p in m) if (!exports.hasOwnProperty(p)) exports[p] = m[p];
}
Object.defineProperty(exports, "__esModule", { value: true });
/*
import { InputControl } from "./inputcontrol";
import { InputWithPopup } from "./inputwithpopup";
import { Calendar } from "./calendar";
*/
var dropdown_1 = require("./dropdown");
var datepicker_1 = require("./datepicker");
__export(require("./constants"));
__export(require("./enums"));
__export(require("./utils"));
__export(require("./collection"));
__export(require("./inputcontrol"));
__export(require("./inputwithpopup"));
__export(require("./calendar"));
__export(require("./dropdown"));
__export(require("./datepicker"));
function initializeControls() {
    var elements = document.getElementsByClassName("ms-ctrl-dropdown");
    for (var i = 0; i < elements.length; i++) {
        (new dropdown_1.DropDown()).attach(elements[i]);
    }
    elements = document.getElementsByClassName("ms-ctrl-datePicker");
    for (var i = 0; i < elements.length; i++) {
        (new datepicker_1.DatePicker()).attach(elements[i]);
    }
}
exports.initializeControls = initializeControls;
//# sourceMappingURL=ms-controls.js.map