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
        // Do any additional setup after loading the view, typically from a nib.
    }
    @IBAction func setTextButton() {
        let textBlock : TextBlock = TextBlock()
        
        textBlock.text = "blah"
        
        textLabel.text = textBlock.text
        
    }

}

