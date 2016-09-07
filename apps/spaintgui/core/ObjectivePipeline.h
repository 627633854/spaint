/**
 * spaintgui: ObjectivePipeline.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2016. All rights reserved.
 */

#ifndef H_SPAINTGUI_OBJECTIVEPIPELINE
#define H_SPAINTGUI_OBJECTIVEPIPELINE

#include "MultiScenePipeline.h"

/**
 * \brief An instance of this class represents an ObjectivePaint processing pipeline.
 */
class ObjectivePipeline : public MultiScenePipeline
{
  //#################### CONSTRUCTORS ####################
public:
  /**
   * \brief Constructs an objective pipeline.
   *
   * \param settings          The settings to use for InfiniTAM.
   * \param resourcesDir      The path to the resources directory.
   * \param maxLabelCount     The maximum number of labels that can be in use.
   * \param imageSourceEngine The engine used to provide input images to the SLAM component for the world scene.
   * \param trackerType       The type of tracker to use when reconstructing the world scene.
   * \param trackerParams     The parameters for the tracker (if any).
   * \param mappingMode       The mapping mode that the world scene's SLAM component should use.
   * \param trackingMode      The tracking mode that the world scene's SLAM component should use.
   */
  ObjectivePipeline(const Settings_Ptr& settings, const std::string& resourcesDir, size_t maxLabelCount, const CompositeImageSourceEngine_Ptr& imageSourceEngine,
                    spaint::TrackerType trackerType = spaint::TRACKER_INFINITAM, const std::string& trackerParams = "",
                    spaint::SLAMComponent::MappingMode mappingMode = spaint::SLAMComponent::MAP_VOXELS_ONLY,
                    spaint::SLAMComponent::TrackingMode trackingMode = spaint::SLAMComponent::TRACK_VOXELS);

  //#################### PUBLIC MEMBER FUNCTIONS ####################
public:
  /** Override */
  virtual void set_mode(Mode mode);
};

#endif
