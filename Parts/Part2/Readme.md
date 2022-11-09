University of Pennsylvania, ESE 5190: Intro to Embedded Systems, Lab 2B

    Harish Ramesh, worked with Sugata Sen
    https://www.linkedin.com/in/harishramesh1998/, https://www.linkedin.com/in/sugata-sen/
    Tested on: Lenovo Legion Slim-7, Windows-11; ASUS ROG GL-552 VW, Windows-10
    
### Modifications implemented:
In order to write and read we copied the helper functions given in the code directory of lab_2b_esp, namely the register_read and the register_write. We declared the IO_BANK0_BASE as the register we are using from the data sheet. We read and wrote from this register multiple times with values changinging every cycle. Looking at Ruturaj's code gave us some direction on how to proceed.

### Output
![](https://github.com/harishramesh98/lab-2b-pre/blob/a734d8a8427fd4869052e9314e23ab89fee24004/part_2/images/p2_op.gif)

