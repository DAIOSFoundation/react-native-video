#import <AVFoundation/AVFoundation.h>
#import "AVKit/AVKit.h"
#import "UIView+FindUIViewController.h"
#import "RCTVideoPlayerViewController.h"
#import "RCTVideoPlayerViewControllerDelegate.h"
#import <React/RCTComponent.h>
#import <React/RCTBridgeModule.h>

#if __has_include(<react-native-video/RCTVideoCache.h>)
#import <react-native-video/RCTVideoCache.h>
#import <DVAssetLoaderDelegate/DVURLAsset.h>
#import <DVAssetLoaderDelegate/DVAssetLoaderDelegate.h>
#endif

@class RCTEventDispatcher;
#if __has_include(<react-native-video/RCTVideoCache.h>)
@interface RCTVideo : UIView <RCTVideoPlayerViewControllerDelegate, DVAssetLoaderDelegatesDelegate, AVAssetResourceLoaderDelegate>
#elif TARGET_OS_TV
@interface RCTVideo : UIView <RCTVideoPlayerViewControllerDelegate, AVAssetResourceLoaderDelegate>
#else
@interface RCTVideo : UIView <RCTVideoPlayerViewControllerDelegate, AVPictureInPictureControllerDelegate, AVAssetResourceLoaderDelegate>
#endif

// @property (nonatomic, copy) RCTDirectEventBlock onVideoLoadStart;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoLoad;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoBuffer;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoError;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoProgress;
// @property (nonatomic, copy) RCTDirectEventBlock onBandwidthUpdate;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoSeek;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoEnd;
// @property (nonatomic, copy) RCTDirectEventBlock onTimedMetadata;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoAudioBecomingNoisy;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoFullscreenPlayerWillPresent;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoFullscreenPlayerDidPresent;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoFullscreenPlayerWillDismiss;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoFullscreenPlayerDidDismiss;
// @property (nonatomic, copy) RCTDirectEventBlock onReadyForDisplay;
// @property (nonatomic, copy) RCTDirectEventBlock onPlaybackStalled;
// @property (nonatomic, copy) RCTDirectEventBlock onPlaybackResume;
// @property (nonatomic, copy) RCTDirectEventBlock onPlaybackRateChange;
// @property (nonatomic, copy) RCTDirectEventBlock onVideoExternalPlaybackChange;
// @property (nonatomic, copy) RCTDirectEventBlock onPictureInPictureStatusChanged;
// @property (nonatomic, copy) RCTDirectEventBlock onRestoreUserInterfaceForPictureInPictureStop;
// @property (nonatomic, copy) RCTDirectEventBlock onGetLicense;

@property (nonatomic, copy) RCTBubblingEventBlock onVideoLoadStart;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoLoad;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoBuffer;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoError;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoProgress;
@property (nonatomic, copy) RCTBubblingEventBlock onBandwidthUpdate;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoSeek;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoEnd;
@property (nonatomic, copy) RCTBubblingEventBlock onTimedMetadata;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoAudioBecomingNoisy;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoFullscreenPlayerWillPresent;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoFullscreenPlayerDidPresent;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoFullscreenPlayerWillDismiss;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoFullscreenPlayerDidDismiss;
@property (nonatomic, copy) RCTBubblingEventBlock onReadyForDisplay;
@property (nonatomic, copy) RCTBubblingEventBlock onPlaybackStalled;
@property (nonatomic, copy) RCTBubblingEventBlock onPlaybackResume;
@property (nonatomic, copy) RCTBubblingEventBlock onPlaybackRateChange;
@property (nonatomic, copy) RCTBubblingEventBlock onVideoExternalPlaybackChange;
@property (nonatomic, copy) RCTBubblingEventBlock onPictureInPictureStatusChanged;
@property (nonatomic, copy) RCTBubblingEventBlock onRestoreUserInterfaceForPictureInPictureStop;
@property (nonatomic, copy) RCTBubblingEventBlock onGetLicense;

typedef NS_ENUM(NSInteger, RCTVideoError) {
    RCTVideoErrorFromJSPart,
    RCTVideoErrorLicenseRequestNotOk,
    RCTVideoErrorNoDataFromLicenseRequest,
    RCTVideoErrorNoSPC,
    RCTVideoErrorNoDataRequest,
    RCTVideoErrorNoCertificateData,
    RCTVideoErrorNoCertificateURL,
    RCTVideoErrorNoFairplayDRM,
    RCTVideoErrorNoDRMData
};

- (instancetype)initWithEventDispatcher:(RCTEventDispatcher *)eventDispatcher NS_DESIGNATED_INITIALIZER;

- (AVPlayerViewController*)createPlayerViewController:(AVPlayer*)player withPlayerItem:(AVPlayerItem*)playerItem;

- (void)save:(NSDictionary *)options resolve:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject;
- (void)setLicenseResult:(NSString * )license;
- (BOOL)setLicenseResultError:(NSString * )error;

@end
