cmake_minimum_required(VERSION 3.27)

project(
  garmin_fit_sdk
  LANGUAGES CXX
  VERSION 1.0.0)

# ==================================================================================================

add_library(
  garmin_fit_sdk
  "${CMAKE_CURRENT_LIST_DIR}/src/fit.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_accumulated_field.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_accumulator.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_buffered_mesg_broadcaster.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_buffered_record_mesg_broadcaster.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_crc.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_date_time.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_decode.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field_definition.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_developer_field_description.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_encode.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_field.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_field_base.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_field_definition.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_broadcaster.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_definition.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_mesg_with_event_broadcaster.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_profile.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_protocol_validator.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/src/fit_unicode.cpp")

target_sources(
  garmin_fit_sdk
  PUBLIC
    FILE_SET
    HEADERS
    BASE_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/include
    FILES
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_aad_accel_features_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_aad_accel_features_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_accelerometer_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_accelerometer_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_accumulated_field.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_accumulator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_activity_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_activity_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_channel_id_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_channel_id_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_rx_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_rx_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_tx_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ant_tx_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_aviation_attitude_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_aviation_attitude_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_barometer_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_barometer_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_beat_intervals_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_beat_intervals_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_bike_profile_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_bike_profile_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_blood_pressure_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_blood_pressure_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_buffer_encode.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_buffered_mesg_broadcaster.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_buffered_record_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_buffered_record_mesg_broadcaster.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_buffered_record_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_cadence_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_cadence_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_camera_event_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_camera_event_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_capabilities_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_capabilities_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_chrono_shot_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_chrono_shot_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_chrono_shot_session_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_chrono_shot_session_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_climb_pro_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_climb_pro_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_config.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_connectivity_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_connectivity_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_course_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_course_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_course_point_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_course_point_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_crc.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_date_time.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_decode.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_data_id_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_data_id_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_field.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_field_definition.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_field_description.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_developer_field_description_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_aux_battery_info_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_aux_battery_info_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_info_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_info_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_settings_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_device_settings_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_alarm_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_alarm_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_apnea_alarm_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_apnea_alarm_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_gas_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_gas_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_settings_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_settings_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_summary_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_dive_summary_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_encode.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_event_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_event_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_data_concept_configuration_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_data_concept_configuration_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_data_field_configuration_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_data_field_configuration_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_screen_configuration_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exd_screen_configuration_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exercise_title_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_exercise_title_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_factory.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_base.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_capabilities_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_capabilities_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_definition.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_description_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_field_description_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_capabilities_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_capabilities_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_creator_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_creator_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_id_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_file_id_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_goal_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_goal_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_gps_metadata_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_gps_metadata_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_gyroscope_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_gyroscope_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hr_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hr_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hr_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hr_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrm_profile_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrm_profile_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_status_summary_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_status_summary_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_value_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hrv_value_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_accelerometer_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_accelerometer_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_body_battery_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_body_battery_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_configuration_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_configuration_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_event_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_event_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_gyroscope_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_gyroscope_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_heart_rate_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_heart_rate_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_respiration_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_respiration_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_spo2_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_spo2_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_step_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_step_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_stress_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_stress_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_wrist_temperature_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_hsa_wrist_temperature_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_jump_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_jump_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_lap_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_lap_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_length_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_length_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_magnetometer_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_magnetometer_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_max_met_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_max_met_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_memo_glob_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_memo_glob_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_broadcast_plugin.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_broadcaster.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_capabilities_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_capabilities_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_definition.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_definition_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_with_event.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_with_event_broadcaster.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_mesg_with_event_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_met_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_met_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_hr_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_hr_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_info_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_info_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_monitoring_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_nmea_sentence_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_nmea_sentence_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_obdii_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_obdii_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ohr_settings_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_ohr_settings_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_one_d_sensor_calibration_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_one_d_sensor_calibration_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_pad_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_pad_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_power_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_power_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_profile.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_protocol_validator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_raw_bbi_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_raw_bbi_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_record_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_record_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_respiration_rate_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_respiration_rate_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_runtime_exception.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_schedule_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_schedule_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sdm_profile_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sdm_profile_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_file_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_file_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_id_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_id_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_lap_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_lap_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_leaderboard_entry_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_leaderboard_entry_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_point_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_segment_point_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_session_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_session_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_set_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_set_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_skin_temp_overnight_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_skin_temp_overnight_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_slave_device_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_slave_device_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sleep_assessment_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sleep_assessment_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sleep_level_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sleep_level_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_software_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_software_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_speed_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_speed_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_split_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_split_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_split_summary_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_split_summary_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_spo2_data_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_spo2_data_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sport_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_sport_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_stress_level_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_stress_level_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_tank_summary_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_tank_summary_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_tank_update_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_tank_update_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_three_d_sensor_calibration_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_three_d_sensor_calibration_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_time_in_zone_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_time_in_zone_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_timestamp_correlation_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_timestamp_correlation_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_totals_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_totals_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_training_file_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_training_file_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_unicode.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_user_profile_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_user_profile_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_clip_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_clip_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_description_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_description_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_frame_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_frame_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_title_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_video_title_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_watchface_settings_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_watchface_settings_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weather_alert_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weather_alert_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weather_conditions_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weather_conditions_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weight_scale_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_weight_scale_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_session_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_session_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_step_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_workout_step_mesg_listener.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_zones_target_mesg.hpp
    ${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk/fit_zones_target_mesg_listener.hpp
)

target_include_directories(
  garmin_fit_sdk
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/garmin_fit_sdk>
         $<INSTALL_INTERFACE:include/garmin_fit_sdk>)

add_executable(decode ${CMAKE_CURRENT_LIST_DIR}/src/decode.cpp)
target_link_libraries(decode PRIVATE garmin_fit_sdk)

add_executable(encode ${CMAKE_CURRENT_LIST_DIR}/src/encode.cpp)
target_link_libraries(encode PRIVATE garmin_fit_sdk)

# ==================================================================================================

if(NOT TARGET garmin::garmin_fit_sdk)
  add_library(garmin::garmin_fit_sdk ALIAS garmin_fit_sdk)
endif()

# ==================================================================================================

install(
  TARGETS garmin_fit_sdk
  EXPORT garmin_fit_sdk
  LIBRARY COMPONENT Runtime NAMELINK_COMPONENT Development
  RUNTIME COMPONENT Runtime
  ARCHIVE COMPONENT Development
          FILE_SET HEADERS
          COMPONENT Development)
install(
  EXPORT garmin_fit_sdk
  NAMESPACE garmin::
  DESTINATION lib/cmake/garmin_fit_sdk)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/garmin_fit_sdkConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/garmin_fit_sdk"
  NO_SET_AND_CHECK_MACRO NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/garmin_fit_sdkConfigVersion.cmake"
  COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/garmin_fit_sdkConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/garmin_fit_sdkConfigVersion.cmake
        DESTINATION lib/cmake/garmin_fit_sdk)
