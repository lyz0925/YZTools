//
//  YZAuthFaceOrTouchIDTool.h
//  VertifyFaceOrTouchID
//
//  Created by 李雅珠 on 2020/5/26.
//  Copyright © 2020 李雅珠. All rights reserved.
//  面容或者指纹的认证

#import <UIKit/UIKit.h>
#import <LocalAuthentication/LocalAuthentication.h>

/**
*  TouchID/FaceID 状态
*/
typedef NS_ENUM(NSUInteger, YZAuthFaceOrTouchIDState){
    
    /**
     *  当前设备不支持TouchID/FaceID
     */
    YZAuthFaceOrTouchIDStateNotSupport = 0,
    /**
     *  TouchID/FaceID 验证成功
     */
    YZAuthFaceOrTouchIDStateSuccess = 1,
    
    /**
     *  TouchID/FaceID 验证失败
     */
    YZAuthFaceOrTouchIDStateFail = 2,
    /**
     *  TouchID/FaceID 被用户手动取消
     */
    YZAuthFaceOrTouchIDStateUserCancel = 3,
    /**
     *  用户不使用TouchID/FaceID,选择手动输入密码
     */
    YZAuthFaceOrTouchIDStateInputPassword = 4,
    /**
     *  TouchID/FaceID 被系统取消 (如遇到来电,锁屏,按了Home键等)
     */
    YZAuthFaceOrTouchIDStateSystemCancel = 5,
    /**
     *  TouchID/FaceID 无法启动,因为用户没有设置密码
     */
    YZAuthFaceOrTouchIDStatePasswordNotSet = 6,
    /**
     *  TouchID/FaceID 无法启动,因为用户没有设置TouchID/FaceID
     */
    YZAuthFaceOrTouchIDStateTouchIDNotSet = 7,
    /**
     *  TouchID/FaceID 无效
     */
    YZAuthFaceOrTouchIDStateTouchIDNotAvailable = 8,
    /**
     *  TouchID/FaceID 被锁定(连续多次验证TouchID/FaceID失败,系统需要用户手动输入密码)
     */
    YZAuthFaceOrTouchIDStateTouchIDLockout = 9,
    /**
     *  当前软件被挂起并取消了授权 (如App进入了后台等)
     */
    YZAuthFaceOrTouchIDStateAppCancel = 10,
    /**
     *  当前软件被挂起并取消了授权 (LAContext对象无效)
     */
    YZAuthFaceOrTouchIDStateInvalidContext = 11,
    /**
     *  系统版本不支持TouchID/FaceID (必须高于iOS 8.0才能使用)
     */
    YZAuthFaceOrTouchIDStateVersionNotSupport = 12
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^YZAuthFaceOrTouchIDStateBlock)(YZAuthFaceOrTouchIDState state, NSError *error);

@interface YZAuthFaceOrTouchIDTool : LAContext

+ (instancetype)sharedInstance ;
/**
 * 启动TouchID/FaceID进行验证
 * @param describe TouchID/FaceID显示的描述
 * @param block 回调状态的block
 */
- (void)showAuthFaceOrTouchIDWithDescribe:(NSString *)describe block:(YZAuthFaceOrTouchIDStateBlock)block;

- (void)showAuthFaceOrTouchIDWithDescribe:(NSString *)describe localizedFallbackTitle:(NSString *)localizedFallbackTitle block:(YZAuthFaceOrTouchIDStateBlock)block;

@end

NS_ASSUME_NONNULL_END
