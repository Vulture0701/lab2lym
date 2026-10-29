
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402240 <p3_dispatch>:
  402240:	endbr64
  402244:	mov    %edi,%eax
  402246:	mov    %esi,%edi
  402248:	cmp    $0x7,%eax
  40224b:	ja     402292 <p3_dispatch+0x52>
  40224d:	notrack jmp *0x405820(,%rax,8)
  402255:	nopl   (%rax)
  402258:	jmp    402210 <p3_case_5>
  40225a:	nopw   0x0(%rax,%rax,1)
  402260:	jmp    4021b0 <p3_case_0>
  402265:	nopl   (%rax)
  402268:	jmp    402200 <p3_case_4>
  40226a:	nopw   0x0(%rax,%rax,1)
  402270:	jmp    4021f0 <p3_case_3>
  402275:	nopl   (%rax)
  402278:	jmp    4021d0 <p3_case_1>
  40227d:	nopl   (%rax)
  402280:	jmp    402220 <p3_case_6>
  402282:	nopw   0x0(%rax,%rax,1)
  402288:	jmp    4021e0 <p3_case_2>
  40228d:	nopl   (%rax)
  402290:	jmp    402230 <p3_case_7>
  402292:	xor    %eax,%eax
  402294:	ret

Disassembly of section .fini:
