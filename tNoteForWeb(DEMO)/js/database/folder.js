// 文件夹数据库
define(function () {

var database = {
    id: "foders",
    description: "The database for folders",
    migrations: [{
        version: 1,
        migrate: function (transaction, next) {
            var store = transaction.db.createObjectStore("folders");
            next();
        }
    }]
};

return database;

});