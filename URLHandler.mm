#import <Cocoa/Cocoa.h>

@interface URLHandler : NSObject
@end

@implementation URLHandler

- (void)handleGetURLEvent:(NSAppleEventDescriptor *)event withReplyEvent:(NSAppleEventDescriptor *)replyEvent
{
    NSString *urlString = [[event paramDescriptorForKeyword:keyDirectObject] stringValue];
    NSLog(@"URL event received: %@", urlString);
}

@end

extern "C" void InitializeURLHandler()
{
    URLHandler *handler = [[URLHandler alloc] init];
    [[NSAppleEventManager sharedAppleEventManager] setEventHandler:handler
                                                       andSelector:@selector(handleGetURLEvent:withReplyEvent:)
                                                     forEventClass:kInternetEventClass
                                                        andEventID:kAEGetURL];

    NSLog(@"URL handler initialized");
}