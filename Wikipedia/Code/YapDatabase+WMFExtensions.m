#import "YapDatabase+WMFExtensions.h"

@implementation YapDatabase (WMFExtensions)

+ (NSString *)wmf_databasePath {
    NSString *databaseName = @"WikipediaYap.sqlite";

    NSURL *baseURL = [[NSFileManager defaultManager] wmf_containerURL];

    NSURL *databaseURL = [baseURL URLByAppendingPathComponent:databaseName isDirectory:NO];

    return databaseURL.filePathURL.path;
}

+ (NSString *)wmf_appSpecificDatabasePath {
    NSString *databaseName = @"WikipediaYap.sqlite";

    NSURL *baseURL = [[NSFileManager defaultManager] URLForDirectory:NSDocumentDirectory
                                                            inDomain:NSUserDomainMask
                                                   appropriateForURL:nil
                                                              create:YES
                                                               error:NULL];

    NSURL *databaseURL = [baseURL URLByAppendingPathComponent:databaseName isDirectory:NO];

    return databaseURL.filePathURL.path;
}

- (YapDatabaseConnection *)wmf_newReadConnection {
    YapDatabaseConnection *conn = [self newConnection];
    conn.objectCacheLimit = 100;
    conn.metadataCacheLimit = 0;
    return conn;
}

- (YapDatabaseConnection *)wmf_newLongLivedReadConnection {
    YapDatabaseConnection *conn = [self newConnection];
    conn.objectCacheLimit = 100;
    conn.metadataCacheLimit = 0;
    [conn beginLongLivedReadTransaction];
    return conn;
}

- (YapDatabaseConnection *)wmf_newWriteConnection {
    YapDatabaseConnection *conn = [self newConnection];
    conn.objectCacheLimit = 0;
    conn.metadataCacheLimit = 0;
    return conn;
}

- (void)wmf_registerView:(YapDatabaseView *)view withName:(NSString *)name {
    [self registerExtension:view withName:name];
}

@end
