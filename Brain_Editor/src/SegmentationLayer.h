#pragma once

// Includes
#include "Spotbrain.h" // Primary Engine Header with most other includes
// #include "Panels/xxx" // Any layer specific Panels

// All Spot Brain features are in the Brain namespace
namespace Brain {
	
	// Segmentation Layer is a child of Layer class in engine
	class SegmentationLayer : public Layer
	{
	public:
		// Constructor/Destructor
		SegmentationLayer();
		virtual ~SegmentationLayer() = default;
		
		// Layer Functions
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		
		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
		
	private:
		// variable for use only within Segmentation Layer
		/* 
		Potential Variables:
		My Matrix: stores image input (cv::imread())
		My updatedMatrix: stores image changes to matrix
		My thresholdMatrix: stores thresholding resuts
		My SegmentationObject: ????
		
		
		
		*/
		
		// Panels
		/*
		SegmentationViewport m_SegmentationViewport;
		SegmentationROIZoom m_SegmentationROIZoom;
		SegmentationProperties m_SegmentationProperties;
		*/
		
		
	};
	
	
	
	
	
	
}