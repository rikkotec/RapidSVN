/*
 * ====================================================================
 * Copyright (c) 2002-2005 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _HIST_VAL_H_INCLUDED_
#define _HIST_VAL_H_INCLUDED_


// wxWidgets
#include "wx/validate.h"


/**
 * Validator class, that supports a history,
 * e.g. for a combo control a list of previously 
 * entered values
 *
 * @see HistoryManager
 */
class HistoryValidator: public wxValidator
{
DECLARE_CLASS(HistoryValidator)
public:
  /**
   * @param settingName name of the setting in
   *                    @a HistoryManager to identify the
   *                    previously used values
   * @param value       this variable will receive the entered message
   * @param dontUpdate  if set to "true" the validator will
   *                    fill the control on initialization but
   *                    will not back-propagate the value
   */
  HistoryValidator (const wxString & settingName, 
                    wxString * value = 0,
                    bool dontUpdate = false);


  /** create a clone of the instane */
  virtual wxObject *
  Clone() const { return new HistoryValidator (*this); }


  /** create a copy of @a val */
  bool 
  Copy(const HistoryValidator & val);


  /* Called when the value in the window must be validated.
   * This function can pop up an error message.
   */
  virtual bool 
  Validate(wxWindow * ) { return TRUE; }


  /** Called to transfer data to the window */
  virtual bool 
  TransferToWindow();


  /** Called to transfer data to the window */
  virtual bool 
  TransferFromWindow();


  /** copy consturctor */
  HistoryValidator (const HistoryValidator & src);

private:
  /** name of the setting to use for this validator */
  wxString m_settingName;


  /** pointer to the string that will get the entered text */
  wxString * m_value;

  /** do we want to update the history manager? */
  bool m_dontUpdate;

  
  /** disallow assignment operator */
  HistoryValidator & operator = (const HistoryValidator &);
};

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */