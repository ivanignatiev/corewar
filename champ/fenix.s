.name		"FENIX"
.comment	"From fire to life"

	aff r1
	live %0
start:	sti r1, %:field1, %1
	sti r1, %:field2, %1
	sti r1, %:field3, %1
	sti r1, %:field4, %1
	sti r1, %:field5, %1
	sti r1, %:field6, %1
	sti r1, %:field7, %1
	sti r1, %:field8, %1
	sti r1, %:field9, %1
	sti r1, %:field10, %1
	sti r1, %:field11, %1
	sti r1, %:field12, %1
	sti r1, %:field13, %1
	sti r1, %:field14, %1
	zjmp %:field1
	fork %:worm
field1:	live %0
field2:	live %0
field3:	live %0
field4:	live %0
field5:	live %0
field6:	live %0
field7:	live %0
field8:	live %0
field9:	live %0
field10: live %0
field11: live %0
field12: live %0
field13: live %0
field14: live %0
	ld %0, r10
	zjmp %:start
worm:	ld %31, r3		# lod start addr of tail
	ld %1, r4		# load commands codes of LIVE to r4 
	ld %5, r5
	fork %:pretail
grow:	sti r4, r3, %1		# save command
	sti r1, r3, %-6         # save argument
	add r3, r5, r3		#
	ld %0, r10		# change CARRY
	zjmp %:grow		# GROW!
pretail: fork %0			# waiting when tail growing and grow live forks
tail:	live %0
