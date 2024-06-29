package com.wzy.j2eelabs.lab5.pojo;

public class DeliveryOrder {
    private int deliveryId;
    private int courierId;
    private String trackingId;
    private String address;
    private String phone;

    public DeliveryOrder() {
    }

    public DeliveryOrder(int courierId, String trackingId, String address, String phone) {
        this.trackingId = trackingId;
        this.courierId = courierId;
        this.address = address;
        this.phone = phone;
    }

    public int getDeliveryId() {
        return deliveryId;
    }

    public void setDeliveryId(int deliveryId) {
        this.deliveryId = deliveryId;
    }

    public String getTrackingId() {
        return trackingId;
    }

    public void setTrackingId(String trackingId) {
        this.trackingId = trackingId;
    }

    public int getCourierId() {
        return courierId;
    }

    public void setCourierId(int courierId) {
        this.courierId = courierId;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return "DeliveryOrder{" +
                "deliveryId=" + deliveryId +
                ", courierId=" + courierId +
                ", trackingId='" + trackingId + '\'' +
                ", address='" + address + '\'' +
                ", phone='" + phone + '\'' +
                '}';
    }

}
