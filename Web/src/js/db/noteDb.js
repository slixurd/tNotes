// 笔记数据库配置

define(['Database'], function (Database) {

var database = new Database('notes', '笔记数据库', 1, 'notes');

return database;

});