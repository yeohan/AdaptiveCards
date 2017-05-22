//
//  ViewController.swift
//  Sample
//
//  Created by Esteban Chavez on 4/13/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import UIKit
import AdaptiveCards

class ViewController: UIViewController {
    @IBOutlet weak var textLabel: UILabel!
    @IBOutlet weak var textInput: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        let mainview = self.view
        let adcviewc = InfoDisplayBuilder()
        mainview?.addSubview(adcviewc.view);
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @IBOutlet weak var textView: UITextView!
    
    @IBAction func setTextButton() {
        let textBlock : TextBlock = TextBlock()
        
        textBlock.text = textInput.text!
        
        let string = textBlock.text;
        
        textLabel.text = string
        
    }

}

