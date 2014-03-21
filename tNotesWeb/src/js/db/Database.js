// 数据库配置类

define(function () {

var Database = function (id, description, version, store) {
    return {
        id: id,
        description: description,
        storeName: store,
        migrations: [{
            version: version,
            migrate: function (transaction, next) {
                var store = transaction.db.createObjectStore(store);
                next();
            }
        }]
    };
};

return Database;

});