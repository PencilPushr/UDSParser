#pragma once

// Frame type codes
typedef enum {
	FRAME_SINGLE = 0,
	FRAME_FIRST = 1,
	FRAME_CONSECUTIVE = 2,
	FRAME_FLOW_CONTROL = 3
} FrameTypeCode;

// Regular (Not 11-bit extended can) frame info
typedef struct _FrameType
{
	unsigned int canID;
	unsigned int PCI : 4; // Believe this is correct.
	FrameTypeCode code;     // Frame type code

	union
	{
		struct
		{
			unsigned int size : 4;  // Payload size (0-7 for classic CAN)
			uint8_t data[7];        // Data bytes
		} sf;

		struct 
		{
			unsigned int size : 12; // Payload size (0-4095)
			uint8_t data[6];        // First frame data
		} ff;  // First Frame
		
		struct 
		{
			unsigned int index : 4; // Sequence index (0-15)
			uint8_t data[7];        // Consecutive frame data
		} cf;  // Consecutive Frame
		
		struct 
		{
			unsigned int flowStatus : 4;   // Flow status
			unsigned int blockSize : 8;    // Block size
			unsigned int separationTime : 8; // Separation time - sometimes called something else
		} fc;  // Flow Control

		uint8_t data[8];
	} frameData;

} FrameType, *PFrameType;