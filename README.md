# Arduino-MIDI-Slider-Controller
A project to hook up slider pots to an Arduino to use as a MIDI controller

# Install 
- Add Pro Micro to the boards manager 
- https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json

# Current Pinout 
- Sliders (Analog): A0, A1, A2, A3, A9
- Buttons (Digital): 5, 7
- LEDs (Digital): 6, 8

# Arduino Pro Micro Pinout
![Pro Micro Pinout](out.png)

# MIDI Control Table
- http://www.onicos.com/staff/iz/formats/midi-cntl.html

<TABLE BORDER>
<TR><TH>2nd byte<TH>Function<TH>3rd byte
<TR ALIGN=CENTER><TD>0x00<TD>Continuous controller #0<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x01<TD>Modulation wheel<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x02<TD>Breath control<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x03<TD>Continuous controller #3<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x04<TD>Foot controller<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x05<TD>Portamento time<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x06<TD>Data Entry<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x07<TD>Main Volume<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x08<TD>Continuous controller #8<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x09<TD>Continuous controller #9<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0A<TD>Continuous controller #10<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0B<TD>Continuous controller #11<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0C<TD>Continuous controller #12<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0D<TD>Continuous controller #13<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0E<TD>Continuous controller #14<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x0F<TD>Continuous controller #15<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x10<TD>Continuous controller #16<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x11<TD>Continuous controller #17<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x12<TD>Continuous controller #18<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x13<TD>Continuous controller #19<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x14<TD>Continuous controller #20<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x15<TD>Continuous controller #21<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x16<TD>Continuous controller #22<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x17<TD>Continuous controller #23<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x18<TD>Continuous controller #24<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x19<TD>Continuous controller #25<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1A<TD>Continuous controller #26<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1B<TD>Continuous controller #27<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1C<TD>Continuous controller #28<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1D<TD>Continuous controller #29<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1E<TD>Continuous controller #30<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x1F<TD>Continuous controller #31<TD>0-127, MSB
<TR ALIGN=CENTER><TD>0x20<TD>Continuous controller #0<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x21<TD>Modulation wheel<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x22<TD>Breath control<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x23<TD>Continuous controller #3<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x24<TD>Foot controller<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x25<TD>Portamento time<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x26<TD>Data entry<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x27<TD>Main volume<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x28<TD>Continuous controller #8<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x29<TD>Continuous controller #9<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2A<TD>Continuous controller #10<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2B<TD>Continuous controller #11<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2C<TD>Continuous controller #12<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2D<TD>Continuous controller #13<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2E<TD>Continuous controller #14<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x2F<TD>Continuous controller #15<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x30<TD>Continuous controller #16<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x31<TD>Continuous controller #17<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x32<TD>Continuous controller #18<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x33<TD>Continuous controller #19<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x34<TD>Continuous controller #20<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x35<TD>Continuous controller #21<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x36<TD>Continuous controller #22<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x37<TD>Continuous controller #23<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x38<TD>Continuous controller #24<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x39<TD>Continuous controller #25<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3A<TD>Continuous controller #26<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3B<TD>Continuous controller #27<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3C<TD>Continuous controller #28<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3D<TD>Continuous controller #29<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3E<TD>Continuous controller #30<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x3F<TD>Continuous controller #31<TD>0-127, LSB
<TR ALIGN=CENTER><TD>0x40<TD>Damper pedal on/off (Sustain)<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x41<TD>Portamento on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x42<TD>Sustenuto on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x43<TD>Soft pedal on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x44<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x45<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x46<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x47<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x48<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x49<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4A<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4B<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4C<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4D<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4E<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x4F<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x50<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x51<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x52<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x53<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x54<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x55<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x56<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x57<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x58<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x59<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5A<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5B<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5C<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5D<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5E<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x5F<TD>Undefined on/off<TD>0=off, 127=on
<TR ALIGN=CENTER><TD>0x60<TD>Data entry +1<TD>127
<TR ALIGN=CENTER><TD>0x61<TD>Data entry -1<TD>127
<TR ALIGN=CENTER><TD>0x62<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x63<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x64<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x65<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x66<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x67<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x67<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x67<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x67<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x67<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x68<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x69<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6A<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6B<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6C<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6D<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6E<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x6F<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x70<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x71<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x72<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x73<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x74<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x75<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x76<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x77<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x78<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x79<TD>Undefined<TD>-
<TR ALIGN=CENTER><TD>0x7A<TD>Local control on/off<TD>0=off    127=on
<TR ALIGN=CENTER><TD>0x7B<TD>All notes off<TD>0
<TR ALIGN=CENTER><TD>0x7C<TD>Omni mode off (includes all notes off)<TD>0
<TR ALIGN=CENTER><TD>0x7D<TD>Omni mode on (includes all notes off)<TD>0
<TR ALIGN=CENTER><TD>0x7E<TD>Poly mode on/off(includes all notes off)<TD>**
<TR ALIGN=CENTER><TD>0x7F<TD>Poly mode on(incl mono=off&amp;all notes off)<TD>0
</TABLE>

<DL>
<DT>**Note:
<DD>This equals the number of channels, or zero if the number of channels
    equals the number of voices in the receiver.
</DL>

