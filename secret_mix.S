
./bomb:     file format elf64-x86-64


Disassembly of section .init:

Disassembly of section .plt:

Disassembly of section .plt.sec:

Disassembly of section .text:

0000000000402630 <secret_mix>:
  402630:	endbr64
  402634:	lea    0x0(,%rdi,8),%eax
  40263b:	sub    %edi,%eax
  40263d:	add    $0xbed2,%eax
  402642:	xor    $0xdae6,%eax
  402647:	ret

Disassembly of section .fini:
