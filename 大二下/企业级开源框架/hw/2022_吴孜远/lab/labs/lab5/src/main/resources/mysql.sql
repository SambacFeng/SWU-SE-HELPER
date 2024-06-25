use ssm;

CREATE TABLE delivery_order (
    delivery_id int auto_increment primary key,
    courier_id INT NOT NULL,
    tracking_id varchar(20) NOT NULL ,
    address VARCHAR(20) NOT NULL,
    phone VARCHAR(20) NOT NULL
);