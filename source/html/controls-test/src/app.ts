import * as MsControls from "ms-js-controls";

window.onload = function (e) {
    // MsControls.initializeControls();
    var checkBox = new MsControls.CheckBox();
    // checkBox.onchange = (sender) => { alert("Changed!") };
    checkBox.attach(document.getElementById("myCheckBox"));

    new MsControls.RadioButton().attach(document.getElementById("myRadioButton1"));
    new MsControls.RadioButton().attach(document.getElementById("myRadioButton2"));
    new MsControls.DropDown().attach(document.getElementById("myDropDown"));
    new MsControls.DatePicker().attach(document.getElementById("myDatePicker"));

    var textBox = new MsControls.TextBox();
    /*
    textBox.onChange = (sender) => {
        document.getElementById("myTextBoxOnChangeTest").innerText = sender.value;
    };
    */
    textBox.attach(document.getElementById("myTextBox"));

    var multilineTextBox = new MsControls.TextBox();
    /*
    multilineTextBox.onChange = (sender) => {
        document.getElementById("myMultilineTextBoxOnChangeTest").innerText = sender.value;
    };
    */
    multilineTextBox.attach(document.getElementById("myMultilineTextBox"));
};