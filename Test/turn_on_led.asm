; -------------------------------------------
;
;	Title:	Turn on Led
;
;	Cofigurations:
;		-	Led connected at pin 0
;		- 	DDRB 	:	0x0D
;		-	PORTB	:	0x0E
; -------------------------------------------

; Put 0x01 at MEM[0x0D]
lui $1, 0x0000		; $1 <- 0 * (2^16)
ori $8, $1, 0x0D	; $8 <- $1 | 0x0D
ori $9, $1, 0x01	; $9 <- $1 | 0x01
sw	$8, 0($9)		; MEM[$8+0] <- $9

; Clean registers 8
lui $8, 0x0000		; %8 <- 0 * (2^16)

; Put 0x01 at MEM[0x0E]
ori $8, $1, 0x0E	; $8 <- $1 | 0x0E
sw	$8, 0($9)		; MEM[$8+0] <- $9