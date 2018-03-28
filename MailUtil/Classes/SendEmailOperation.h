//
//  SendEmailOperation.h
//  CrashLogTest
//
//  Created by xdzhangm on 16/9/20.
//  Copyright © 2016年 isoftstone. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ConcurrentOperation.h"
#import "SKPSMTPMessage.h"

@protocol SendEmailOperationDelegate
@required

-(void)messageSent:(SKPSMTPMessage *)message;
-(void)messageFailed:(SKPSMTPMessage *)message error:(NSError *)error;

@end

@interface SendEmailOperation : ConcurrentOperation
@property (nonatomic, copy) NSString *to;
@property (nonatomic, copy) NSString *cc;
@property (nonatomic, copy) NSString *bcc;
@property (nonatomic, copy) NSString *subject;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *path;
@property(nonatomic, assign) id <SendEmailOperationDelegate> delegate;

// 如果没有设置，则用全局的。
@property (nonatomic, copy) NSString *mailServer;
@property (nonatomic, copy) NSString *fromEmail;
@property (nonatomic, copy) NSString *login;
@property (nonatomic, copy) NSString *password;

# pragma mark 初始化配置信息
+ (void)setupDefaultConfig;

+ (void)setupConfigWithServer:(NSString *)server
                     withFrom:(NSString *)from
                    withLogin:(NSString *)login
                 withPassword:(NSString *)password;

# pragma mark 发送邮件
+ (void)sendEmail:(SendEmailOperation *)operation;

# pragma mark init
- (instancetype)initWithTo:(NSString *)to
                   subject:(NSString *)subject
                      body:(NSString *)body;
- (instancetype)initWithTo:(NSString *)to
                   subject:(NSString *)subject
                      body:(NSString *)body
                      path:(NSString *)path;
- (instancetype)initWithTo:(NSString *)to
                        cc:(NSString *)cc
                       bcc:(NSString *)bcc
                   subject:(NSString *)subject
                      body:(NSString *)body
                      path:(NSString *)path;
@end
