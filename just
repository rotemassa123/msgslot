int i;
  printk("Invoking device_write(%p,%ld)\n", file, length);
  for( i = 0; i < length && i < BUF_LEN; ++i )
  {
    get_user(the_message[i], &buffer[i]);
    if( 1 == encryption_flag )
      the_message[i] += 1;
  }

  // return the number of input characters used
  return i;