/*
 * ====================================================================
 * Copyright (c) 2002 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _CHECKOUT_ACTION_H_INCLUDED_
#define _CHECKOUT_ACTION_H_INCLUDED_

// app
#include "checkout_dlg.hpp"
#include "action_thread.hpp"

class CheckoutAction:public ActionThread
{
public:
  /**
   * Constructor
   *
   * @param parent parent window
   * @param tr
   */
  CheckoutAction (wxFrame * parent, Tracer * tr);

  void Perform ();

protected:
  void *Entry ();

private:
  CheckoutData m_data;
  wxFrame *m_parent;

};

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */
