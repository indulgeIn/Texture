//
//  PhotoFeedModel.h
//  Texture
//
//  Copyright (c) 2014-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under the BSD-style license found in the
//  LICENSE file in the /ASDK-Licenses directory of this source tree. An additional
//  grant of patent rights can be found in the PATENTS file in the same directory.
//
//  Modifications to this file made after 4/13/2017 are: Copyright (c) through the present,
//  Pinterest, Inc.  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//

#import "PhotoModel.h"
#import <IGListKit/IGListKit.h>

typedef NS_ENUM(NSInteger, PhotoFeedModelType) {
  PhotoFeedModelTypePopular,
  PhotoFeedModelTypeLocation,
  PhotoFeedModelTypeUserPhotos
};

@interface PhotoFeedModel : NSObject <IGListDiffable>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithPhotoFeedModelType:(PhotoFeedModelType)type imageSize:(CGSize)size NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) NSArray<PhotoModel *> *photos;

- (NSUInteger)totalNumberOfPhotos;
- (NSUInteger)numberOfItemsInFeed;
- (PhotoModel *)objectAtIndex:(NSUInteger)index;
- (NSInteger)indexOfPhotoModel:(PhotoModel *)photoModel;

- (void)updatePhotoFeedModelTypeUserId:(NSUInteger)userID;

- (void)clearFeed;
- (void)requestPageWithCompletionBlock:(void (^)(NSArray *))block numResultsToReturn:(NSUInteger)numResults;
- (void)refreshFeedWithCompletionBlock:(void (^)(NSArray *))block numResultsToReturn:(NSUInteger)numResults;

@end
