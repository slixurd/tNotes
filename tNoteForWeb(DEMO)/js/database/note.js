// 文件夹数据库
define(function () {

var database = {
    id: "notes",
    description: "The database for notes",
    migrations: [{
        version: 1,
        migrate: function (transaction, next) {
            var store = transaction.db.createObjectStore("notes");
            next();
        }
    }]
};

return database;

});