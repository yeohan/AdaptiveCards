/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public class ActionsConfig {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected ActionsConfig(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ActionsConfig obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_ActionsConfig(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public void setShowCard(ShowCardActionConfig value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_showCard_set(swigCPtr, this, ShowCardActionConfig.getCPtr(value), value);
  }

  public ShowCardActionConfig getShowCard() {
    long cPtr = AdaptiveCardObjectModelJNI.ActionsConfig_showCard_get(swigCPtr, this);
    return (cPtr == 0) ? null : new ShowCardActionConfig(cPtr, false);
  }

  public void setActionsOrientation(ActionsOrientation value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_actionsOrientation_set(swigCPtr, this, value.swigValue());
  }

  public ActionsOrientation getActionsOrientation() {
    return ActionsOrientation.swigToEnum(AdaptiveCardObjectModelJNI.ActionsConfig_actionsOrientation_get(swigCPtr, this));
  }

  public void setActionAlignment(ActionAlignment value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_actionAlignment_set(swigCPtr, this, value.swigValue());
  }

  public ActionAlignment getActionAlignment() {
    return ActionAlignment.swigToEnum(AdaptiveCardObjectModelJNI.ActionsConfig_actionAlignment_get(swigCPtr, this));
  }

  public void setButtonSpacing(long value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_buttonSpacing_set(swigCPtr, this, value);
  }

  public long getButtonSpacing() {
    return AdaptiveCardObjectModelJNI.ActionsConfig_buttonSpacing_get(swigCPtr, this);
  }

  public void setMaxActions(long value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_maxActions_set(swigCPtr, this, value);
  }

  public long getMaxActions() {
    return AdaptiveCardObjectModelJNI.ActionsConfig_maxActions_get(swigCPtr, this);
  }

  public void setSpacing(Spacing value) {
    AdaptiveCardObjectModelJNI.ActionsConfig_spacing_set(swigCPtr, this, value.swigValue());
  }

  public Spacing getSpacing() {
    return Spacing.swigToEnum(AdaptiveCardObjectModelJNI.ActionsConfig_spacing_get(swigCPtr, this));
  }

  public static ActionsConfig Deserialize(SWIGTYPE_p_Json__Value json, ActionsConfig defaultValue) {
    return new ActionsConfig(AdaptiveCardObjectModelJNI.ActionsConfig_Deserialize(SWIGTYPE_p_Json__Value.getCPtr(json), ActionsConfig.getCPtr(defaultValue), defaultValue), true);
  }

  public ActionsConfig() {
    this(AdaptiveCardObjectModelJNI.new_ActionsConfig(), true);
  }

}
