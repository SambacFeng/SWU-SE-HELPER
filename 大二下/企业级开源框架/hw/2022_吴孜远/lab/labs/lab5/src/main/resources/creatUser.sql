use ssm;

CREATE TABLE users (
       id INT AUTO_INCREMENT PRIMARY KEY,
       courier_id VARCHAR(20) NOT NULL UNIQUE,
       password VARCHAR(20) NOT NULL-- 注意：实际应用中不应该存储明文密码
);

-- 插入用户1
INSERT INTO users (courier_id, password) VALUES ('111', '111');

-- 插入用户2
INSERT INTO users (courier_id, password) VALUES ('222', '222');

-- 插入用户3
INSERT INTO users (courier_id, password) VALUES ('333', '333');

-- 插入用户4
INSERT INTO users (courier_id, password) VALUES ('444', '444');