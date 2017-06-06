//
//  ViewController.swift
//  NFC Test Drive
//
//  Created by Omar Allaham on 6/6/17.
//  Copyright © 2017 movingatom. All rights reserved.
//

import UIKit
import CoreNFC
import Foundation

class ViewController: UIViewController, NFCNDEFReaderSessionDelegate {

   var session: NFCNDEFReaderSession?
   override func viewDidLoad() {
      super.viewDidLoad()
      // Do any additional setup after loading the view, typically from a nib.
   }

   override func viewDidAppear(_ animated: Bool) {
      super.viewDidAppear(animated)

      session = NFCNDEFReaderSession(delegate: self, queue: nil, invalidateAfterFirstRead: false)

      if session?.isReady ?? false {
         session?.begin()
      }
   }

   override func viewWillDisappear(_ animated: Bool) {
      super.viewWillDisappear(animated)

      session?.invalidate()
   }

   override func didReceiveMemoryWarning() {
      super.didReceiveMemoryWarning()
      // Dispose of any resources that can be recreated.
   }

   func readerSession(_ session: NFCNDEFReaderSession, didDetectNDEFs messages: [NFCNDEFMessage]) {
      alert("Tags found", messages.map { String(describing: $0) + "\n" } )
   }

   func readerSession(_ session: NFCNDEFReaderSession, didInvalidateWithError error: Error) {
      alert("Error", error.localizedDescription)
   }

   func alert(_ title: String, _ messages: [String]) {
      alert(title, messages.reduce("") { $0 + $1 + "\n" })
   }

   func alert(_ title: String, _ message: String) {
      present(UIAlertController.init(title: title, message: message, preferredStyle: .alert), animated: true)
   }

   deinit {
      session?.invalidate()
   }
}
