//
//  NFCISO15693ReaderSession.h
//  CoreNFC
//
//  Copyright © 2017 Apple. All rights reserved.
//
#ifndef NFCISO15693ReaderSession_h
#define NFCISO15693ReaderSession_h

#ifndef CoreNFC_H
#error Please import <CoreNFC/CoreNFC.h> from your source file
#endif

#import <Foundation/Foundation.h>

@protocol NFCReaderSessionDelegate;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ISO15693 reader session

/*!
 * @class NFCISO15693ReaderSession
 *
 * @discussion Reader session for processing ISO15693 tags.  @link [NFCReaderSessionDelegate readerSession:didDetectTags:] @link/ will return tag objects that
 *             are conformed to the NFCISO15693Tag protocol.  This session requires the "com.apple.developer.nfc.readersession.formats" entitlement in your process.
 *
 * NOTE:
 * Only one NFCReaderSession can be active at any time in the system. Subsequent opened sessions will get queued up and processed by the system in FIFO order.
 */
API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, macos, tvos)
@interface NFCISO15693ReaderSession : NFCReaderSession

- (instancetype)init NS_UNAVAILABLE;

/*!
 * @method initWithQueue:
 *
 * @param delegate  The session will hold a weak ARC reference to this @link NFCReaderSessionDelegate @link/ object.
 * @param queue     A dispatch queue where NFCReaderSessionDelegate delegate callbacks will be dispatched to.  A <i>nil</i> value will
 *                  cause the creation of a serial dispatch queue internally for the session.  The session object will retain the provided dispatch queue.
 *
 * @return          A new NFCISO15693ReaderSession instance.
 */
- (instancetype)initWithDelegate:(id<NFCReaderSessionDelegate>)delegate queue:(nullable dispatch_queue_t)queue NS_DESIGNATED_INITIALIZER;

NS_ASSUME_NONNULL_END

@end

#endif
