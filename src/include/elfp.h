/*
 * File: elfp.h
 *
 * Description: Listing of all API exposed to the programmer
 *
 * License: 
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                  Version 2, December 2004
 *  
 * Copyright (C) 2019 Adwaith Gautham <adwait.gautham@gmail.com>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *          DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 * TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 * 0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#ifndef _ELFP_H
#define _ELFP_H

#include <elf.h>

/*
 * elfp_init: Initializes the library. 
 *      * MUST be called before any other library functions are called.
 *
 * @return: 0 on success, -1 on failure.
 */
int
elfp_init();


/*
 * elfp_fini: Cleans up everything and deinits the library.
 */
void
elfp_fini();


/*
 * elfp_open: Opens the specfied ELF file and returns a handle.
 *
 * @arg0: Path / name of ELF File
 *
 * @return: A non-negative integer - handle on success.
 *              (-1) on failure.
 * 	
 * 	* This handle should be used in all further functions.
 */
int
elfp_open(const char *elfp_elf_path);


/*
 * elfp_close: Closes everything about the specified handle.
 *
 * @arg0: File handle obtained from an elfp_open call.
 *
 * @return: 0 on success, -1 on failure.
 */
int
elfp_close(int handle);

/******************************************************************************
 * Parsing the ELF Header.
 *
 * 1. elfp_dump_ehdr: An in-built function which dumps the ELF Header in
 * 	human readable form.
 *
 * 2. elfp_get_ehdr: A function which returns a reference to an elfp_ehdr
 * 	instance, using which the programmer can write a dump function.
 *
 * 3. Decode functions for all members of header which are present in 
 * 	encoded form.
 *****************************************************************************/

/*
 * elfp_dump_ehdr:
 *
 * @arg0: File Handle returned by elfp_open()
 *
 * @return: 0 on success, -1 on failure.
 */
int
elfp_dump_ehdr(int handle);

/*
 * elfp_get_ehdr:
 *
 * @arg0: File Handle returned by elfp_open()
 *
 * @return: Pointer to ELF header.
 * 	* A void pointer is returned because we wouldn't know
 * 	if it is a 32-bit or 64-bit object till e_ident is parsed.
 */
void*
elfp_get_ehdr(int handle);

/*
 * Decode functions:
 *
 * If you want to parse the ELF header on your own, 
 * you can make use of these decode functions. 
 * 
 * All the members of ELF header present in encoded form have a 
 * decode function below. Other members can be printed as-is.
 */

/*
 * elfp_ehdr_decode_class: Decodes the class and returns a
 * decoded, human understandable string.
 *
 * @arg0: Class
 *
 * @return: A string.
 */
const char*
elfp_ehdr_decode_class(unsigned long int class);

/*
 * elfp_ehdr_decode_dataenc: Decodes the type of Data Encoding
 * used to pack this ELF file.
 *
 * @arg0: Data encoding byte
 *
 * @return: An equivalent meaningful string.
 */
const char*
elfp_ehdr_decode_dataenc(unsigned long int data_enc);

/*
 * elfp_ehdr_decode_version: Decodes the ELF version.
 *
 * @arg0: Version
 *
 * @return: A string
 */

const char*
elfp_ehdr_decode_version(unsigned long int version);

/*
 * elfp_ehdr_decode_osabi: Decodes the type of OSABI this ELF file
 * abides by.
 *
 * @arg0: The OSABI byte
 *
 * @return: A string
 */
const char*
elfp_ehdr_decode_osabi(unsigned long int osabi);

/*
 * elfp_ehdr_decode_type: Decodes the type of ELF file.
 *
 * @arg0: Type in encoded form
 *
 * @return: Type in decoded form.
 */
const char*
elfp_ehdr_decode_type(unsigned long int type);

/*
 * elfp_ehdr_decode_machine: Decodes the type of architecture
 * this ELF file was built for.
 *
 * @arg0: machine in encoded form
 *
 * @return: Machine in decoded form.
 */
const char*
elfp_ehdr_decode_machine(unsigned long int machine);

#endif /* _ELFP_H */
