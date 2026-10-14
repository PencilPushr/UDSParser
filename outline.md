# The core idea/outline:

obd protocol
can protocol


line 385
RQ, 		Single-Frame, 			Size:3, 				SID[0x22]:Read Data by identifier, 	Desc[0xF187]:Manufacturer spare part number
R, 			First-Frame, 			Size:14, 				62 F1 87 38 56 30
RQ, 		Multi-frame-request
R, 			Consecutive-Frame, 		i = 1 [nibbles left:8], 39 30 37 34 30 34 45
R, 			Consecutive-Frame, 		i = 2 [nibbles left:1], 20
RQ,  		Single-Frame, 			Size:3, 				SID[0x22]:Read Data by identifier, 	Desc[0xF189]: Manufacturer EU software version
R, 			Single-Frame, 			Size:7,					62 F1 89 30 30 30 33
RQ,
R
R
RQ, 	Multi-frame-request
Broadcast,	

719,02:31.913,Trace,7E0 07 34 AA 31 05 07 FF 00

07 is size
34 = mode (rq download)
AA encryption and compression identifier 
	Should be 1 or A for the nibbles - If it is anything else, it's unknown
		first nibble: compression
		second nibble: encryption
		
	00	-> no encryption/compression
	x0	-> compression
	0x	-> encryption
	xx 	-> encrypted and compressed (only if AA or 11)
	
	
