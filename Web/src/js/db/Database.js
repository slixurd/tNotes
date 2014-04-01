// 数据库配置类

define(function () {

var Database = function (id, description, version, storeName) {
    return {
        id: id,
        description: description,
        storeName: storeName,
        migrations: [{
            version: version,
            migrate: function (transaction, next) {
                var store = transaction.db.createObjectStore(storeName);
                next();
            }
        }]
    };
};

return Database;

});