#include "hw08.h"

#include <string.h>

/**
 * Grammar:
 *
 * expr := term expr_rest
 * expr_rest := '+' expr | '-' expr | {}
 *
 * term := factor term_rest
 * term_rest = '*' term | {}
 *
 * factor := int | '(' expr ')'
 */

#ifndef INSTRUCTOR_EXPR
enum parse_result parse_expr(struct stream *s) { 
  if(parse_term(s) == PARSE_FAILURE) return PARSE_FAILURE;
  if(parse_expr_rest(s) == PARSE_FAILURE) return PARSE_FAILURE;
  return PARSE_SUCCESS; }

enum parse_result parse_expr_rest(struct stream *s) { 
  struct token tok = peek(s);
  if(tok.type == TOK_BINOP && (tok.start[0] == '+' || tok.start[0] == '-')){
    next(s);
    if(parse_expr(s) == PARSE_FAILURE) return PARSE_FAILURE;
  }
  return PARSE_SUCCESS; }
#endif

#ifndef INSTRUCTOR_TERM
enum parse_result parse_term(struct stream *s) { 
  if(parse_factor(s) == PARSE_FAILURE) return PARSE_FAILURE;
  if (parse_term_rest(s) == PARSE_FAILURE) return PARSE_FAILURE;
  return PARSE_SUCCESS; }

enum parse_result parse_term_rest(struct stream *s) { 
  struct token tok = peek(s);
  if(tok.type == TOK_BINOP && tok.start[0] == '*'){
    next(s);
    if(parse_term(s) == PARSE_FAILURE) return PARSE_FAILURE;
  }
  return PARSE_SUCCESS; }
#endif

#ifndef INSTRUCTOR_FACTOR
enum parse_result parse_factor(struct stream *s) {
  struct token tok = peek(s);
  if(tok.type == TOK_LITERAL){
    next(s);
    return PARSE_SUCCESS;
  }
  if(tok.type == TOK_LPAREN){
    next(s);
    if(parse_expr(s) == PARSE_FAILURE) return PARSE_FAILURE;
  }
  tok = peek(s);
  if(tok.type != TOK_RPAREN) return PARSE_FAILURE;
  next(s);
  return PARSE_SUCCESS; }
#endif

// You do NOT need to modify this function!
enum parse_result is_valid_expr(const char *expr) {
  // Create the stream
  struct stream s = {.text = expr, .pos = 0, .length = strlen(expr)};

  // Try to parse an expr and make sure there's nothing left to parse
  if (parse_expr(&s) == PARSE_SUCCESS && next(&s).type == TOK_EOF) {
    return PARSE_SUCCESS;
  }
  return PARSE_FAILURE;
}
