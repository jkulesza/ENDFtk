/** 
 *  @brief Return the number of lines in this MF5 section
 */
long NC() const {

  long NC = 1;
  for ( const auto& entry : this->subsections_ ) { NC += entry.NC(); }
  return NC;
};
