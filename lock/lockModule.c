
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
	return PAM_SUCCESS ;
}


/* this function is ripped from pam_unix/support.c, it lets us do IO via PAM */
int converse( pam_handle_t *pamh, int nargs, struct pam_message **message, struct pam_response **response ) {
	int retval ;
	struct pam_conv *conv ;

	retval = pam_get_item( pamh, PAM_CONV, (const void **) &conv ) ; 
	if( retval==PAM_SUCCESS ) {
		retval = conv->conv( nargs, (const struct pam_message **) message, response, conv->appdata_ptr ) ;
	}

	return retval ;
}


/* expected hook, this is where custom stuff happens */
PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
	int retval ;
	int i ;
    
	
	/* comparing user input with known code */
	if( strcmp(input, code)==0 ) {
		/* good to go! */
		free( input ) ;
		return PAM_SUCCESS ;
	} else {
		/* wrong code */
		free( input ) ;
		return PAM_AUTH_ERR ;
	}

	/* we shouldn't read this point, but if we do, we might as well return something bad */
	return PAM_AUTH_ERR ;
}

int main(){
	
	int x;
	char flag[100];
		
	while(1){
		gets(flag);
		
		printf(“%s”, flag);
		
		/*if(strcmp(flag, "OSLOCK: SUCCESS_ENTER") == 0){
			
			printf("true\n");
		}else{
			
			printf("false\n");
		}*/
	}	
		
		
}
