#ifndef _GenericAnalysis_h
#define _GenericAnalysis_h


#include "HistoContainer.h"

/** base class from which user analyses must inherit */
class GenericAnalysis
{
public:
  /** set branch addresses for the given tree
      and set active / inactivate the branches */
  virtual void setBranchAddresses(TTree *tree) = 0;

  /** this is called for each event in the input tree
      and is typically the place to fill histograms
      using container->Fill(..) and container->Fill2D(..)
  */
  virtual void analyze(HistoContainer *container) = 0;

};

/*

  a shared object with a user analysis must also contain the following
  function:

  GenericAnalysis *makeInstance();

  This must create an instance of the user analysis class and return it.

*/
#endif