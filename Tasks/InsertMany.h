#ifndef MONGODB_ASYNC_INSERTMANY_H
#define MONGODB_ASYNC_INSERTMANY_H

#include "../BaseHeader.h"
#include "../MongoDbHeader.h"
#include "../TaskContext.h"

typedef function<void(bool err, mongocxx::result::insert_many)> InsertManyCompletionHandler;

class InsertManyTask: public TaskContext {
public:
    string collection;
    document_vector_ptr documents;
    InsertManyCompletionHandler completionHandler;
    InsertManyTask(io_service& targetService, string collection, document_vector_ptr documents, InsertManyCompletionHandler completionHandler)
            : TaskContext(targetService), collection(collection), documents(documents), completionHandler(completionHandler) {
    }
};

#endif //MONGODB_ASYNC_INSERTMANY_H
