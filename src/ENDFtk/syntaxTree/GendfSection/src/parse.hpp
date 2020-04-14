section::GendfType const parse(long& lineNumber) {
  auto position = this->buffer().begin();
  auto end = this->buffer().end();

  HeadRecord head( position, end, lineNumber );
  return { head, position, end, lineNumber, head.MAT() };
}

section::GendfType const parse() {
  long lineNumber = 1;
  return this->parse(lineNumber);
}
