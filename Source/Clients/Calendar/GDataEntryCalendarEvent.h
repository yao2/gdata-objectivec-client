/* Copyright (c) 2007 Google Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

//
//  GDataEntryCalendarEvent.h
//

#import <Cocoa/Cocoa.h>

#import "GDataEntryEvent.h"
#import "GDataWho.h"
#import "GDataLink.h"

#undef _EXTERN
#undef _INITIALIZE_AS
#ifdef GDATACALENDAREVENT_DEFINE_GLOBALS
#define _EXTERN 
#define _INITIALIZE_AS(x) =x
#else
#define _EXTERN extern
#define _INITIALIZE_AS(x)
#endif

_EXTERN NSString* kGDataNamespaceGCal _INITIALIZE_AS(@"http://schemas.google.com/gCal/2005");
_EXTERN NSString* kGDataNamespaceGCalPrefix _INITIALIZE_AS(@"gCal");


// CalendarEventEntry extensions
@interface GDataQuickAddProperty : GDataBoolValueConstruct <GDataExtension>
+ (NSString *)extensionElementURI;
+ (NSString *)extensionElementPrefix;
+ (NSString *)extensionElementLocalName;
@end

@interface GDataSendEventNotifications : GDataBoolValueConstruct <GDataExtension>
+ (NSString *)extensionElementURI;
+ (NSString *)extensionElementPrefix;
+ (NSString *)extensionElementLocalName;
@end

@interface GDataResourceProperty : GDataBoolValueConstruct <GDataExtension>
+ (NSString *)extensionElementURI;
+ (NSString *)extensionElementPrefix;
+ (NSString *)extensionElementLocalName;
@end

// CalendarEventEntry categories for extensions
@interface GDataWho (GDataCalendarEntryEventExtensions)
- (NSArray *)resourceProperties;
- (void)setResourceProperties:(NSArray *)arr;
- (void)addResourceProperty:(GDataResourceProperty *)obj;
@end

@class GDataWebContent;
@interface GDataLink (GDataCalendarEntryEventExtensions)
- (NSArray *)webContents;
- (void)setWebContents:(NSArray *)arr;  
- (void)addWebContent:(GDataWebContent *)obj;
@end


@interface GDataEntryCalendarEvent : GDataEntryEvent {
}

+ (NSDictionary *)calendarEventNamespaces;

+ (GDataEntryCalendarEvent *)calendarEvent;

- (BOOL)shouldSendEventNotifications;
- (void)setShouldSendEventNotifications:(BOOL)flag;

- (BOOL)isQuickAdd;
- (void)setIsQuickAdd:(BOOL)flag;

- (GDataLink *)webContentLink;
- (GDataWebContent *)webContent;
@end
