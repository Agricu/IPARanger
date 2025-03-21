#import <CommonCrypto/CommonDigest.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma clang diagnostic ignored "-Wunused-variable"

@interface NSTask : NSObject
@property (copy) NSArray * arguments; 
@property (retain) id standardOutput; 
@property (retain) id standardError; 
@property (readonly) int terminationStatus; 
@property (readonly) int processIdentifier;
-(void)waitUntilExit;
-(id)launchPath;
-(void)launch;
-(void)setLaunchPath:(id)arg1 ;
-(void)setStandardInput:(id)arg1 ;
@property(copy) NSString *currentDirectoryPath;
@end

typedef void (^AlertActionBlock)(void);
typedef void (^AlertActionBlockWithTextField)(UITextField *);
typedef void (^AlertTextFieldBlock)(UITextField *);

@interface IPARUtils : NSObject
+ (NSDictionary *)executeCommandAndGetJSON:(NSString *)launchPath arg1:(NSString *)arg1 arg2:(NSString *)arg2 arg3:(NSString *)arg3;
+ (NSDictionary<NSString*,NSArray*> *)setupTaskAndPipesWithCommand:(NSString *)command;
+ (NSDictionary<NSString*,NSArray*> *)setupTaskAndPipesWithCommandposix:(NSString *)launchPath arg1:(NSString *)arg1 
  arg2:(NSString *)arg2 arg3:(NSString *)arg3;
+ (void)setupUnzipTask:(NSString *)ipaFilePath directoryPath:(NSString *)directoryPath file:(NSString *)fileToUnzip;
+ (NSString *)sha256ForFileAtPath:(NSString *)filePath;
+ (id)getKeyFromFile:(NSString *)key defaultValueIfNil:(NSString *)defaultValue;
+ (void)saveKeyToFile:(NSString *)key withValue:(NSString *)value;
+ (void)accountDetailsToFile:(NSString *)userEmail authName:(NSString *)authName authenticated:(NSString *)authenticated;
+ (NSString *)emojiFlagForISOCountryCode:(NSString *)countryCode;
+ (void)getAppIconFromApple:(NSString *)bundleId completion:(void (^)(UIImage *appIcon))completion;
+ (NSString *)humanReadableSizeForBytes:(long long)bytes;
+ (void)animateClickOnCell:(UITableViewCell *)cell;
+ (void)presentDialogWithTitle:(NSString *)title 
                    message:(NSString *)message
                    hasTextfield:(BOOL)hasTextfield
                    withTextfieldBlock:(AlertTextFieldBlock)textFieldBlock
                    alertConfirmationBlock:(AlertActionBlockWithTextField)confirmationBlock
                    withConfirmText:(NSString *)confirmText
                    alertCancelBlock:(AlertActionBlock)cancelBlock
                    withCancelText:(NSString *)cancelText
                    presentOn:(id)viewController;
+ (UIActivityIndicatorView *)createActivitiyIndicatorWithPoint:(CGPoint)point;
+ (void)cancelScript;
+ (UIButton *)createButtonWithImageName:(NSString *)imageName title:(NSString *)title fontSize:(CGFloat)fontSize selectorName:(NSString *)selectorName frame:(CGRect)frame;
+ (unsigned long long)calculateFolderSize:(NSString *)folderPath;
+ (void)openGithub;
@end

