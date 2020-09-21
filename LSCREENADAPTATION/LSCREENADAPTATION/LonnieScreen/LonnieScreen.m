//
//  LonnieScreen.m
//  LSCREENADAPTATION
//
//  Created by lonnie(罗伟男) on 2018/5/19.
//  Copyright © 2018年 lonnie. All rights reserved.
//

#import "LonnieScreen.h"

/*所需适配机型-屏幕宽*/
CGFloat const SCREEN_WIDTH_iPhone3GS_4_4S       = 320.0f;
CGFloat const SCREEN_WIDTH_iPhone5_5C_5S_5SE    = 320.0f;
CGFloat const SCREEN_WIDTH_iPhone6_6S_7_8       = 375.0f;
CGFloat const SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus  = 414.0f;
CGFloat const SCREEN_WIDTH_iPhoneX_Xs_11Pro        = 375.0f;
CGFloat const SCREEN_WIDTH_iPhoneXsMax_XR_11_11ProMax          = 414.0f;

/*所需适配机型-屏幕高*/
CGFloat const SCREEN_HEIGHT_iPhone3GS_4_4S      = 480.0f;
CGFloat const SCREEN_HEIGHT_iPhone5_5C_5S_5SE   = 568.0f;
CGFloat const SCREEN_HEIGHT_iPhone6_6S_7_8      = 667.0f;
CGFloat const SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus = 736.0f;
CGFloat const SCREEN_HEIGHT_iPhoneX_Xs_11Pro             = 812.0f;
CGFloat const SCREEN_HEIGHT_iPhoneXsMax_XR_11_11ProMax     = 896.0f;

@implementation LonnieScreen
/*共享*/
+ (instancetype)shareAdapter{
    static dispatch_once_t onceToken;
    static LonnieScreen * _instance = nil;
    dispatch_once(&onceToken, ^{
        _instance = [[self alloc] init];
    });
    return _instance;
}

/*重载方法*/
- (instancetype)init{
    if (self = [super init]) {
        self.defaultType = AdapterPhoneType_iPhone5_5C_5S_5SE;
    }
    return self;
}
/*设置默认类型*/
- (void)setDefaultType:(AdapterPhoneType)defaultType {
    _defaultType = defaultType;
    switch (_defaultType) {
        case AdapterPhoneType_iPhone3GS_4_4S:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone3GS_4_4S;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone3GS_4_4S;
            break;
        case AdapterPhoneType_iPhone5_5C_5S_5SE:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone5_5C_5S_5SE;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone5_5C_5S_5SE;
            break;
        case AdapterPhoneType_iPhone6_6S_7_8:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone6_6S_7_8;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone6_6S_7_8;
            break;
        case AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus;
            break;
        case AdapterPhoneType_iPhoneX_Xs_11Pro:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhoneX_Xs_11Pro;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhoneX_Xs_11Pro;
            break;
        case AdapterPhoneType_iPhoneXsMax_XR_11_11ProMax:
            _defaultScreenWidth  = SCREEN_WIDTH_iPhoneXsMax_XR_11_11ProMax;
            _defaultScreenHeight = SCREEN_HEIGHT_iPhoneXsMax_XR_11_11ProMax;
        case AdapterPhoneTypeOther:
            break;
        default:
            break;
    }
}

@end
