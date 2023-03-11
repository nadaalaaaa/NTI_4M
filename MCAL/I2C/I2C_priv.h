/*
 * I2C_priv.h
 *
 * Created: 05/03/2023 09:36:28
 *  Author: dell
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_


#define TWBR        *((volatile u8 * ) (0X20))
#define TWCR		*((volatile u8 * ) (0X56))
#define TWSR		*((volatile u8 * ) (0X21))
#define TWDR        *((volatile u8 * ) (0X23))
#define TWAR        *((volatile u8 * ) (0X22))



#define START_ACK                0x08
// start already transmitted

#define SLAVE_ADD_AND_WR_ACK     0x18
// Master transmit -> slave address + Write request, slave send ACK

#define SLAVE_ADD_AND_WR_NACK     0x20
// Master transmit -> slave address + Write request, slave send NACK



#define REP_START           0x10
// repeated start

#define SLAVE_ADD_AND_RD_ACK           0x40
// Master transmit -> slave address + read request, slave send ACK

#define SLAVE_ADD_AND_RD_NACK           0x48
// Master transmit -> slave address + read request, slave send NACK



#define WR_BYTE_ACK              0x28
// Master transmit data,and slave send ACK

#define WR_BYTE_NACK              0x30
// Master transmit data,and slave send NACK



#define SLAVE_ADD_RCVD_WR_REQ    0x60
// means that slave address is received with write req

#define SLAVE_ADD_RCVD_WR_ACK_SENT   0x68
// means that slave address is received with write req and ACK sent

#define SLAVE_ADD_RCVD_RD_REQ    0xA8
// means that slave address is received with read req

#define SLAVE_ADD_RCVD_RD_ACK_SENT   0xB0
// means that slave address is received with read req and ACK sent

#define SLAVE_ADD_RCVD_GEN_REQ    0x70
// means that slave address is received with general req

#define SLAVE_ADD_RCVD_GEN_ACK_SENT   0x78
// means that slave address is received with general req and ACK sent

#define SLAVE_STOP_OR_REP_START_RCVD    0xA0
// Check for STOP/REPEATED START received

#define SLAVE_DATA_TRANS_ACK    0xB8
// Check for data transmitted &ack received

#define SLAVE_DATA_TRANS_NACK   0xC0
// Check for data transmitted &nack received

#define SLAVE_LAST_BYTE_TRANS_ACK   0xC8
// Check for last byte transmitted &ack received

#define SLAVE_DATA_RECEIVED      0x80
// Check for data received &ack returned

#define SLAVE_DATA_RECEIVED_ACK      0x90
// Check for data received &ack returned

#define SLAVE_DATA_RECEIVED_N      0x88
// Check for data received &nack returned

#define SLAVE_DATA_RECEIVED_NACK      0x98
// Check for data received &nack returned

#define RD_BYTE_WITH_NACK        0x58
// Master received data with not ACK





#endif /* I2C_PRIV_H_ */