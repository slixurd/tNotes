// 文件夹数据库配置

define(['Database'], function (Database) {

var database = new Database('folders', '文件夹数据库', 1, 'folders');

return database;

});