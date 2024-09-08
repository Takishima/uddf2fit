from xsdata.formats.dataclass.parsers import XmlParser

parser = XmlParser()
data = parser.parse('../data/garmin_mk3.uddf', 'uddf')
# data.profiledata.repetitiongroup[0].dive[0].samples.waypoint[2]
