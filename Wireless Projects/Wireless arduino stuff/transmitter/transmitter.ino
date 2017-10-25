// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);	  // Debugging only
    Serial.println("setup"); // Prints "Setup to the serial monitor"

   
    vw_set_tx_pin(12);          // Sets pin D12 as the TX pin
    vw_set_ptt_inverted(true);  // Required for DR3100
    vw_setup(4000);	        // Bits per sec
}

void loop()
{
    const char *msg = "hello";   // Message to be sent
    digitalWrite(13, true);      // Flash a light to show transmitting
    vw_send((uint8_t *)msg, strlen(msg)); //Sending the message
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(13, false);   // Turn the LED off.
    delay(50);                 // A short gap.
} 
