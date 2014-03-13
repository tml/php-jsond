/* Generated by re2c 0.13.6 on Wed Mar 12 18:01:45 2014 */
/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Jakub Zelenka <bukka@php.net>                                |
  +----------------------------------------------------------------------+
*/

#include "php.h"
#include "php_jsond_scanner.h"
#include "php_jsond_scanner_defs.h"
#include "jsond_parser.tab.h"

#define	YYCTYPE     char
#define	YYCURSOR    s->cursor
#define	YYLIMIT     s->limit
#define	YYMARKER    s->marker
#define	YYCTXMARKER s->ctxmarker

#define YYGETCONDITION()        s->state
#define YYSETCONDITION(yystate) s->state = yystate

#define	YYFILL(n)

#define PHP_JSON_TOKEN(token)  PHP_JSON_T_##token
#define	PHP_JSON_TOKEN_RETURN(token)  return PHP_JSON_TOKEN(token)
#define PHP_JSON_CONDITION_SET(condition) YYSETCONDITION(yyc##condition)
#define PHP_JSON_CONDITION_GOTO(condition) goto yyc_##condition

#define PHP_JSON_SCANNER_COPY_ESC() php_json_scanner_copy_string(s, 0)
#define PHP_JSON_SCANNER_COPY_UTF() php_json_scanner_copy_string(s, 5)
#define PHP_JSON_SCANNER_COPY_UTF_SP() php_json_scanner_copy_string(s, 11)


static void php_json_scanner_copy_string(php_json_scanner *s, int esc_size)
{
	size_t len = s->cursor - s->str_start - esc_size - 1;
	if (len) {
		memcpy(s->pstr, s->str_start, len);
		s->pstr += len;
	}
}

static int php_json_hex_to_int(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'F')
	{
		return c - ('A' - 10);
	}
	else if (c >= 'a' && c <= 'f')
	{
		return c - ('a' - 10);
	}
	else
	{
		/* this should never happened */
		return -1;
	}
}

static int php_json_ucs2_to_int_ex(php_json_scanner *s, int size, int start)
{
	int i, code = 0;
	char *pc = s->cursor - start;
	for (i = 0; i < size; i++) {
		code |= php_json_hex_to_int(*(pc--)) << (i * 4);
	}
	return code;
}

static int php_json_ucs2_to_int(php_json_scanner *s, int size)
{
	return php_json_ucs2_to_int_ex(s, size, 1);
}

void php_json_scanner_init(php_json_scanner *s, char *str, int str_len, long options)
{
	s->cursor = str;
	s->limit = str + str_len;
	s->options = options;
	PHP_JSON_CONDITION_SET(JS);
}

int php_json_scan(php_json_scanner *s)
{

std:
	s->token = s->cursor;


	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;
		if (YYGETCONDITION() < 1) {
			goto yyc_JS;
		} else {
			if (YYGETCONDITION() < 2) {
				goto yyc_STR_P1;
			} else {
				goto yyc_STR_P2;
			}
		}
/* *********************************** */
yyc_JS:
		{
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0, 128,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				 64,  64,  64,  64,  64,  64,  64,  64, 
				 64,  64,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};
			yych = *YYCURSOR;
			if (yych <= '9') {
				if (yych <= ' ') {
					if (yych <= '\n') {
						if (yych <= 0x00) goto yy3;
						if (yych <= 0x08) goto yy5;
						if (yych <= '\t') goto yy7;
						goto yy9;
					} else {
						if (yych == '\r') goto yy10;
						if (yych <= 0x1F) goto yy5;
						goto yy7;
					}
				} else {
					if (yych <= ',') {
						if (yych == '"') goto yy11;
						if (yych <= '+') goto yy5;
						goto yy13;
					} else {
						if (yych <= '-') goto yy15;
						if (yych <= '/') goto yy5;
						if (yych <= '0') goto yy16;
						goto yy18;
					}
				}
			} else {
				if (yych <= 'm') {
					if (yych <= '\\') {
						if (yych <= ':') goto yy19;
						if (yych == '[') goto yy21;
						goto yy5;
					} else {
						if (yych <= ']') goto yy23;
						if (yych == 'f') goto yy25;
						goto yy5;
					}
				} else {
					if (yych <= 'z') {
						if (yych <= 'n') goto yy26;
						if (yych == 't') goto yy27;
						goto yy5;
					} else {
						if (yych <= '{') goto yy28;
						if (yych == '}') goto yy30;
						goto yy5;
					}
				}
			}
yy3:
			++YYCURSOR;
			{
		if (s->limit < s->cursor) {
			PHP_JSON_TOKEN_RETURN(EOI);
		} else {
			s->errcode = PHP_JSON_ERROR_SYNTAX;
			PHP_JSON_TOKEN_RETURN(ERROR);
		}
	}
yy5:
			++YYCURSOR;
yy6:
			{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		PHP_JSON_TOKEN_RETURN(ERROR);
	}
yy7:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy61;
yy8:
			{ goto std; }
yy9:
			yych = *++YYCURSOR;
			goto yy8;
yy10:
			yych = *++YYCURSOR;
			if (yych == '\n') goto yy59;
			goto yy6;
yy11:
			++YYCURSOR;
			{
		s->str_start = s->cursor;
		s->str_esc = 0;
		PHP_JSON_CONDITION_SET(STR_P1);
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy13:
			++YYCURSOR;
			{ return ','; }
yy15:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy6;
			if (yych <= '0') goto yy58;
			if (yych <= '9') goto yy46;
			goto yy6;
yy16:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy48;
			} else {
				if (yych <= 'E') goto yy49;
				if (yych == 'e') goto yy49;
			}
yy17:
			{
		zend_bool bigint = 0, negative = s->token[0] == '-';
		int digits = s->cursor - s->token - negative;
		int max_digits = MAX_LENGTH_OF_LONG - 1;
		if (digits >= max_digits) {
			if (digits == max_digits) {
				int cmp = strncmp(s->token + negative, long_min_digits, max_digits);
				if (!(cmp < 0 || (cmp == 0 && negative))) {
					bigint = 1;
				}
			} else {
				bigint = 1;
			}
		}
		if (!bigint) {
			ZVAL_LONG(&s->value, strtol(s->token, NULL, 10));
			PHP_JSON_TOKEN_RETURN(INT);
		} else if (s->options & PHP_JSON_BIGINT_AS_STRING) {
			ZVAL_STRINGL(&s->value, s->token, s->cursor - s->token, 1);
			PHP_JSON_TOKEN_RETURN(STRING);
		} else {
			ZVAL_DOUBLE(&s->value, zend_strtod(s->token, NULL));
			PHP_JSON_TOKEN_RETURN(DOUBLE);
		}
	}
yy18:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy47;
yy19:
			++YYCURSOR;
			{ return ':'; }
yy21:
			++YYCURSOR;
			{ return '['; }
yy23:
			++YYCURSOR;
			{ return ']'; }
yy25:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'a') goto yy41;
			goto yy6;
yy26:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'u') goto yy37;
			goto yy6;
yy27:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'r') goto yy32;
			goto yy6;
yy28:
			++YYCURSOR;
			{ return '{'; }
yy30:
			++YYCURSOR;
			{ return '}'; }
yy32:
			yych = *++YYCURSOR;
			if (yych == 'u') goto yy34;
yy33:
			YYCURSOR = YYMARKER;
			if (yyaccept <= 1) {
				if (yyaccept == 0) {
					goto yy17;
				} else {
					goto yy6;
				}
			} else {
				goto yy52;
			}
yy34:
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy33;
			++YYCURSOR;
			{
		ZVAL_TRUE(&s->value);
		PHP_JSON_TOKEN_RETURN(TRUE);
	}
yy37:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy33;
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy33;
			++YYCURSOR;
			{
		ZVAL_NULL(&s->value);
		PHP_JSON_TOKEN_RETURN(NUL);
	}
yy41:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy33;
			yych = *++YYCURSOR;
			if (yych != 's') goto yy33;
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy33;
			++YYCURSOR;
			{
		ZVAL_FALSE(&s->value);
		PHP_JSON_TOKEN_RETURN(FALSE);
	}
yy46:
			yyaccept = 0;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy47:
			if (yybm[0+yych] & 64) {
				goto yy46;
			}
			if (yych <= 'D') {
				if (yych != '.') goto yy17;
			} else {
				if (yych <= 'E') goto yy49;
				if (yych == 'e') goto yy49;
				goto yy17;
			}
yy48:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy33;
			if (yych <= '0') goto yy55;
			if (yych <= '9') goto yy56;
			goto yy33;
yy49:
			yych = *++YYCURSOR;
			if (yych <= '-') {
				if (yych == '+') goto yy50;
				if (yych <= ',') goto yy33;
			} else {
				if (yych <= '/') goto yy33;
				if (yych <= '0') goto yy51;
				if (yych <= '9') goto yy53;
				goto yy33;
			}
yy50:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy33;
			if (yych <= '0') goto yy51;
			if (yych <= '9') goto yy53;
			goto yy33;
yy51:
			++YYCURSOR;
yy52:
			{
		ZVAL_DOUBLE(&s->value, zend_strtod(s->token, NULL));
		PHP_JSON_TOKEN_RETURN(DOUBLE);
	}
yy53:
			++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= '/') goto yy52;
			if (yych <= '9') goto yy53;
			goto yy52;
yy55:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'E') goto yy49;
			if (yych == 'e') goto yy49;
			goto yy52;
yy56:
			yyaccept = 2;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= 'D') {
				if (yych <= '/') goto yy52;
				if (yych <= '9') goto yy56;
				goto yy52;
			} else {
				if (yych <= 'E') goto yy49;
				if (yych == 'e') goto yy49;
				goto yy52;
			}
yy58:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy48;
				goto yy17;
			} else {
				if (yych <= 'E') goto yy49;
				if (yych == 'e') goto yy49;
				goto yy17;
			}
yy59:
			yych = *++YYCURSOR;
			goto yy8;
yy60:
			++YYCURSOR;
			yych = *YYCURSOR;
yy61:
			if (yybm[0+yych] & 128) {
				goto yy60;
			}
			goto yy8;
		}
/* *********************************** */
yyc_STR_P1:
		yych = *YYCURSOR;
		if (yych <= 0xDF) {
			if (yych <= '[') {
				if (yych <= 0x1F) goto yy64;
				if (yych == '"') goto yy68;
				goto yy66;
			} else {
				if (yych <= '\\') goto yy70;
				if (yych <= 0x7F) goto yy66;
				if (yych <= 0xC1) goto yy72;
				goto yy74;
			}
		} else {
			if (yych <= 0xEF) {
				if (yych <= 0xE0) goto yy75;
				if (yych <= 0xEC) goto yy76;
				if (yych <= 0xED) goto yy77;
				goto yy78;
			} else {
				if (yych <= 0xF0) goto yy79;
				if (yych <= 0xF3) goto yy80;
				if (yych <= 0xF4) goto yy81;
				goto yy72;
			}
		}
yy64:
		++YYCURSOR;
		{
		s->errcode = PHP_JSON_ERROR_CTRL_CHAR;
		PHP_JSON_TOKEN_RETURN(ERROR);
	}
yy66:
		++YYCURSOR;
yy67:
		{ PHP_JSON_CONDITION_GOTO(STR_P1); }
yy68:
		++YYCURSOR;
		{
		char *str;
		size_t len = s->cursor - s->str_start - s->str_esc - 1;
		if (len == 0) {
			PHP_JSON_CONDITION_SET(JS);
			ZVAL_EMPTY_STRING(&s->value);
			PHP_JSON_TOKEN_RETURN(ESTRING);
		}
		str = emalloc(len + 1);
		str[len] = 0;
		ZVAL_STRINGL(&s->value, str, len, 0);
		if (s->str_esc) {
			s->pstr = Z_STRVAL(s->value);
			s->cursor = s->str_start;
			PHP_JSON_CONDITION_SET(STR_P2);
			PHP_JSON_CONDITION_GOTO(STR_P2);
		} else {
			memcpy(Z_STRVAL(s->value), s->str_start, len);
			PHP_JSON_CONDITION_SET(JS);
			PHP_JSON_TOKEN_RETURN(STRING);
		}
	}
yy70:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 'e') {
			if (yych <= '/') {
				if (yych == '"') goto yy94;
				if (yych >= '/') goto yy94;
			} else {
				if (yych <= '\\') {
					if (yych >= '\\') goto yy94;
				} else {
					if (yych == 'b') goto yy94;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'f') goto yy94;
				if (yych == 'n') goto yy94;
			} else {
				if (yych <= 's') {
					if (yych <= 'r') goto yy94;
				} else {
					if (yych <= 't') goto yy94;
					if (yych <= 'u') goto yy96;
				}
			}
		}
yy71:
		{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		PHP_JSON_TOKEN_RETURN(ERROR);
	}
yy72:
		++YYCURSOR;
yy73:
		{
		s->errcode = PHP_JSON_ERROR_UTF8;
		PHP_JSON_TOKEN_RETURN(ERROR);
	}
yy74:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy73;
		if (yych <= 0xBF) goto yy85;
		goto yy73;
yy75:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x9F) goto yy73;
		if (yych <= 0xBF) goto yy93;
		goto yy73;
yy76:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy73;
		if (yych <= 0xBF) goto yy92;
		goto yy73;
yy77:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy73;
		if (yych <= 0x9F) goto yy91;
		goto yy73;
yy78:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy73;
		if (yych <= 0xBF) goto yy90;
		goto yy73;
yy79:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x8F) goto yy73;
		if (yych <= 0xBF) goto yy88;
		goto yy73;
yy80:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy73;
		if (yych <= 0xBF) goto yy86;
		goto yy73;
yy81:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy73;
		if (yych >= 0x90) goto yy73;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy84;
yy83:
		YYCURSOR = YYMARKER;
		if (yyaccept <= 1) {
			if (yyaccept == 0) {
				goto yy71;
			} else {
				goto yy73;
			}
		} else {
			goto yy105;
		}
yy84:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych >= 0xC0) goto yy83;
yy85:
		yych = *++YYCURSOR;
		goto yy67;
yy86:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych >= 0xC0) goto yy83;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy88:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych >= 0xC0) goto yy83;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy90:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy91:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy92:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy93:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy83;
		if (yych <= 0xBF) goto yy85;
		goto yy83;
yy94:
		++YYCURSOR;
		{
		s->str_esc++;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy96:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy83;
				if (yych >= '1') goto yy98;
			} else {
				if (yych <= '@') goto yy83;
				if (yych <= 'C') goto yy98;
				goto yy99;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy98;
				if (yych <= '`') goto yy83;
				goto yy98;
			} else {
				if (yych <= 'd') goto yy99;
				if (yych <= 'f') goto yy98;
				goto yy83;
			}
		}
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy83;
			if (yych <= '0') goto yy118;
			if (yych <= '7') goto yy119;
			goto yy100;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy83;
				goto yy100;
			} else {
				if (yych <= '`') goto yy83;
				if (yych <= 'f') goto yy100;
				goto yy83;
			}
		}
yy98:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych <= '9') goto yy100;
			goto yy83;
		} else {
			if (yych <= 'F') goto yy100;
			if (yych <= '`') goto yy83;
			if (yych <= 'f') goto yy100;
			goto yy83;
		}
yy99:
		yych = *++YYCURSOR;
		if (yych <= 'B') {
			if (yych <= '7') {
				if (yych <= '/') goto yy83;
			} else {
				if (yych <= '9') goto yy101;
				if (yych <= '@') goto yy83;
				goto yy101;
			}
		} else {
			if (yych <= '`') {
				if (yych <= 'F') goto yy102;
				goto yy83;
			} else {
				if (yych <= 'b') goto yy101;
				if (yych <= 'f') goto yy102;
				goto yy83;
			}
		}
yy100:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych <= '9') goto yy115;
			goto yy83;
		} else {
			if (yych <= 'F') goto yy115;
			if (yych <= '`') goto yy83;
			if (yych <= 'f') goto yy115;
			goto yy83;
		}
yy101:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych <= '9') goto yy106;
			goto yy83;
		} else {
			if (yych <= 'F') goto yy106;
			if (yych <= '`') goto yy83;
			if (yych <= 'f') goto yy106;
			goto yy83;
		}
yy102:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy103;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy103:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy104;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy104:
		++YYCURSOR;
yy105:
		{
		s->errcode = PHP_JSON_ERROR_UTF16;
		PHP_JSON_TOKEN_RETURN(ERROR);
	}
yy106:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy107;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy107:
		yyaccept = 2;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych != '\\') goto yy105;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy83;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy110;
		if (yych != 'd') goto yy83;
yy110:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy83;
		if (yych <= 'F') goto yy111;
		if (yych <= 'b') goto yy83;
		if (yych >= 'g') goto yy83;
yy111:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy112;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy112:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy113;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy113:
		++YYCURSOR;
		{
		s->str_esc += 8;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy115:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy116;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy116:
		++YYCURSOR;
		{
		s->str_esc += 3;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy118:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych <= '7') goto yy123;
			if (yych <= '9') goto yy120;
			goto yy83;
		} else {
			if (yych <= 'F') goto yy120;
			if (yych <= '`') goto yy83;
			if (yych <= 'f') goto yy120;
			goto yy83;
		}
yy119:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy120;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy120:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy121;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy121:
		++YYCURSOR;
		{
		s->str_esc += 4;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy123:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy83;
			if (yych >= ':') goto yy83;
		} else {
			if (yych <= 'F') goto yy124;
			if (yych <= '`') goto yy83;
			if (yych >= 'g') goto yy83;
		}
yy124:
		++YYCURSOR;
		{
		s->str_esc += 5;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
/* *********************************** */
yyc_STR_P2:
		yych = *YYCURSOR;
		if (yych == '"') goto yy130;
		if (yych == '\\') goto yy132;
		++YYCURSOR;
		{ PHP_JSON_CONDITION_GOTO(STR_P2); }
yy130:
		++YYCURSOR;
		YYSETCONDITION(yycJS);
		{
		PHP_JSON_SCANNER_COPY_ESC();
		PHP_JSON_TOKEN_RETURN(STRING);
	}
yy132:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych == 'u') goto yy134;
yy133:
		{
		char esc;
		PHP_JSON_SCANNER_COPY_ESC();
		switch (*s->cursor) {
			case 'b':
				esc = '\b';
				break;
			case 'f':
				esc = '\f';
				break;
			case 'n':
				esc = '\n';
				break;
			case 'r':
				esc = '\r';
				break;
			case 't':
				esc = '\t';
				break;
			case '\\':
			case '/':
			case '"':
				esc = *s->cursor;
				break;
			default:
				s->errcode = PHP_JSON_ERROR_SYNTAX;
				PHP_JSON_TOKEN_RETURN(ERROR);
		}
		*(s->pstr++) = esc;
		++YYCURSOR;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy134:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy135;
				if (yych <= '0') goto yy136;
				goto yy137;
			} else {
				if (yych <= '@') goto yy135;
				if (yych <= 'C') goto yy137;
				goto yy138;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy137;
				if (yych >= 'a') goto yy137;
			} else {
				if (yych <= 'd') goto yy138;
				if (yych <= 'f') goto yy137;
			}
		}
yy135:
		YYCURSOR = YYMARKER;
		goto yy133;
yy136:
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy135;
			if (yych <= '0') goto yy153;
			if (yych <= '7') goto yy154;
			goto yy140;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy135;
				goto yy140;
			} else {
				if (yych <= '`') goto yy135;
				if (yych <= 'f') goto yy140;
				goto yy135;
			}
		}
yy137:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych <= '9') goto yy140;
			goto yy135;
		} else {
			if (yych <= 'F') goto yy140;
			if (yych <= '`') goto yy135;
			if (yych <= 'f') goto yy140;
			goto yy135;
		}
yy138:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych <= '7') goto yy140;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'B') goto yy139;
			if (yych <= '`') goto yy135;
			if (yych >= 'c') goto yy135;
		}
yy139:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych <= '9') goto yy144;
			goto yy135;
		} else {
			if (yych <= 'F') goto yy144;
			if (yych <= '`') goto yy135;
			if (yych <= 'f') goto yy144;
			goto yy135;
		}
yy140:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy141;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy141:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy142;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy142:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 4);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xe0 | (utf16 >> 12));
		*(s->pstr++) = (char) (0x80 | ((utf16 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy144:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy145;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy145:
		yych = *++YYCURSOR;
		if (yych != '\\') goto yy135;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy135;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy148;
		if (yych != 'd') goto yy135;
yy148:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy135;
		if (yych <= 'F') goto yy149;
		if (yych <= 'b') goto yy135;
		if (yych >= 'g') goto yy135;
yy149:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy150;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy150:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy151;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy151:
		++YYCURSOR;
		{
		int utf32, utf16_hi, utf16_lo;
		utf16_hi = php_json_ucs2_to_int(s, 4);
		utf16_lo = php_json_ucs2_to_int_ex(s, 4, 7);
		utf32 = ((utf16_hi & 0x3FF) << 10) + (utf16_lo & 0x3FF) + 0x10000;
		PHP_JSON_SCANNER_COPY_UTF_SP();
		*(s->pstr++) = (char) (0xf0 | (utf32 >> 18));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 12) & 0x3f));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf32 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy153:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych <= '7') goto yy158;
			if (yych <= '9') goto yy155;
			goto yy135;
		} else {
			if (yych <= 'F') goto yy155;
			if (yych <= '`') goto yy135;
			if (yych <= 'f') goto yy155;
			goto yy135;
		}
yy154:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy155;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy155:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy156;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy156:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 3);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xc0 | (utf16 >> 6));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy158:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy135;
			if (yych >= ':') goto yy135;
		} else {
			if (yych <= 'F') goto yy159;
			if (yych <= '`') goto yy135;
			if (yych >= 'g') goto yy135;
		}
yy159:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 2);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) utf16;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
	}


}
