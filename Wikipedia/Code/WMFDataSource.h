#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WMFDataSourceDelegate;

@protocol WMFDataSource <NSObject>

@property (nonatomic, weak) id<WMFDataSourceDelegate> delegate;

@property (nonatomic, getter=areGranularDelegateCallbacksEnabled) BOOL granularDelegateCallbacksEnabled; //determines whether or not the data source will call the optional WMFDataSourceDelegate methods that notify the delagate of indvidual changes.

- (NSInteger)numberOfItems;

- (NSInteger)numberOfSections;
- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (nullable NSString *)titleForSectionIndex:(NSInteger)index;

- (nullable id)objectAtIndexPath:(NSIndexPath *)indexPath;

- (void)readWithBlock:(void (^)(YapDatabaseReadTransaction *_Nonnull transaction, YapDatabaseViewTransaction *_Nonnull view))block;

- (nullable id)readAndReturnResultsWithBlock:(id (^)(YapDatabaseReadTransaction *_Nonnull transaction, YapDatabaseViewTransaction *_Nonnull view))block;

- (void)readWriteAndReturnUpdatedKeysWithBlock:(NSArray<NSString *> * (^)(YapDatabaseReadWriteTransaction *_Nonnull transaction, YapDatabaseViewTransaction *_Nonnull view))block;

@end

@protocol WMFDataSourceDelegate <NSObject>

- (void)dataSourceDidUpdateAllData:(id<WMFDataSource>)dataSource;

@optional
- (void)dataSourceWillBeginUpdates:(id<WMFDataSource>)dataSource;
- (void)dataSourceDidFinishUpdates:(id<WMFDataSource>)dataSource;

- (void)dataSource:(id<WMFDataSource>)dataSource didDeleteSectionsAtIndexes:(NSIndexSet *)indexes;
- (void)dataSource:(id<WMFDataSource>)dataSource didInsertSectionsAtIndexes:(NSIndexSet *)indexes;

- (void)dataSource:(id<WMFDataSource>)dataSource didDeleteRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)dataSource:(id<WMFDataSource>)dataSource didInsertRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
- (void)dataSource:(id<WMFDataSource>)dataSource didMoveRowFromIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath;
- (void)dataSource:(id<WMFDataSource>)dataSource didUpdateRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
;

@end

NS_ASSUME_NONNULL_END
