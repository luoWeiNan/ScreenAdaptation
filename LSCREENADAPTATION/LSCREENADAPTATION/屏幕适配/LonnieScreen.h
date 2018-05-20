//
//  LonnieScreen.h
//  LSCREENADAPTATION
//
//  Created by lonnie(罗伟男) on 2018/5/19.
//  Copyright © 2018年 lonnie. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*适配手机类型*/
typedef NS_ENUM(NSInteger,AdapterPhoneType) {
    AdapterPhoneType_iPhone3GS_4_4S    = 0,
    AdapterPhoneType_iPhone5_5C_5S_5SE = 1,
    AdapterPhoneType_iPhone6_6S_7_8    = 2,
    AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus = 3,
    AdapterPhoneType_iPhoneX           = 4,
    AdapterPhoneTypeOther              = 5
};

/*所需适配机型-屏幕宽*/
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone3GS_4_4S;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone5_5C_5S_5SE;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone6_6S_7_8;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhone6Plus_6SPlus_7Plus_8Plus;
UIKIT_EXTERN CGFloat const SCREEN_WIDTH_iPhoneX;
/*所需适配机型-屏幕高*/
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone3GS_4_4S;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone5_5C_5S_5SE;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone6_6S_7_8;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus;
UIKIT_EXTERN CGFloat const SCREEN_HEIGHT_iPhoneX;

/*屏幕宽度*/
static inline CGFloat tScreenWidth() {
    return [UIScreen mainScreen].bounds.size.width;
}
/*幕高度*/
static inline CGFloat tScreenHeight() {
    return [UIScreen mainScreen].bounds.size.height;
}

/*当前屏幕类型*/
static inline AdapterPhoneType tCurrentType() {
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone3GS_4_4S) return AdapterPhoneType_iPhone3GS_4_4S;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone5_5C_5S_5SE) return AdapterPhoneType_iPhone5_5C_5S_5SE;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone6_6S_7_8) return AdapterPhoneType_iPhone6_6S_7_8;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhone6Plus_6SPlus_7Plus_8Plus) return AdapterPhoneType_iPhone6Plus_6SPlus_7Plus_8Plus;
    if (tScreenHeight() == SCREEN_HEIGHT_iPhoneX) return AdapterPhoneType_iPhoneX;
    return AdapterPhoneTypeOther;
}

@interface LonnieScreen : NSObject
/*屏幕适配参考类型 默认为TXAdapterPhoneType_iPhone5*/
@property(nonatomic)AdapterPhoneType defaultType;
@property(nonatomic,readonly)CGFloat defaultScreenWidth;
@property(nonatomic,readonly)CGFloat defaultScreenHeight;
/*共享*/
+ (instancetype)shareAdapter;

@end
/*
 注：屏幕及字体是以屏幕宽度来适配的
 */

/*真实字体大小*/
static inline CGFloat tRealFontSize(CGFloat defaultSize) {
    if ([LonnieScreen shareAdapter].defaultType == tCurrentType())
        return defaultSize;
    return tScreenWidth() / [LonnieScreen shareAdapter].defaultScreenWidth * defaultSize;
}

/*真实长度*/
static inline CGFloat tRealLength(CGFloat defaultLength) {
    if ([LonnieScreen shareAdapter].defaultType == tCurrentType())
        return defaultLength;
    return tScreenWidth()/[LonnieScreen shareAdapter].defaultScreenWidth * defaultLength;
}
