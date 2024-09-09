// Copyright (c) 2005-2023 Code Synthesis.
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis gives permission
// to link this program with the Xerces-C++ library (or with modified
// versions of Xerces-C++ that use the same license as Xerces-C++), and
// distribute linked combinations including the two. You must obey the GNU
// General Public License version 2 in all respects for all of the code
// used other than Xerces-C++. If you modify this copy of the program, you
// may extend this exception to your version of the program, but you are
// not obligated to do so. If you do not wish to do so, delete this
// exception statement from your version.
//
// Furthermore, Code Synthesis makes a special exception for the Free/Libre
// and Open Source Software (FLOSS) which is described in the accompanying
// FLOSSE file.
//

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "dcalarmType.hxx"

#include "markerType.hxx"

namespace streit
{
  // dcalarmType
  //

  const dcalarmType::acknowledge_optional& dcalarmType::
  acknowledge () const
  {
    return this->acknowledge_;
  }

  dcalarmType::acknowledge_optional& dcalarmType::
  acknowledge ()
  {
    return this->acknowledge_;
  }

  void dcalarmType::
  acknowledge (const acknowledge_type& x)
  {
    this->acknowledge_.set (x);
  }

  void dcalarmType::
  acknowledge (const acknowledge_optional& x)
  {
    this->acknowledge_ = x;
  }

  void dcalarmType::
  acknowledge (::std::unique_ptr< acknowledge_type > x)
  {
    this->acknowledge_.set (std::move (x));
  }

  const dcalarmType::period_optional& dcalarmType::
  period () const
  {
    return this->period_;
  }

  dcalarmType::period_optional& dcalarmType::
  period ()
  {
    return this->period_;
  }

  void dcalarmType::
  period (const period_type& x)
  {
    this->period_.set (x);
  }

  void dcalarmType::
  period (const period_optional& x)
  {
    this->period_ = x;
  }

  const dcalarmType::alarmType_type& dcalarmType::
  alarmType () const
  {
    return this->alarmType_.get ();
  }

  dcalarmType::alarmType_type& dcalarmType::
  alarmType ()
  {
    return this->alarmType_.get ();
  }

  void dcalarmType::
  alarmType (const alarmType_type& x)
  {
    this->alarmType_.set (x);
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // dcalarmType
  //

  dcalarmType::
  dcalarmType (const alarmType_type& alarmType)
  : ::xml_schema::type (),
    acknowledge_ (this),
    period_ (this),
    alarmType_ (alarmType, this)
  {
  }

  dcalarmType::
  dcalarmType (const dcalarmType& x,
               ::xml_schema::flags f,
               ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    acknowledge_ (x.acknowledge_, f, this),
    period_ (x.period_, f, this),
    alarmType_ (x.alarmType_, f, this)
  {
  }

  dcalarmType::
  dcalarmType (const ::xercesc::DOMElement& e,
               ::xml_schema::flags f,
               ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    acknowledge_ (this),
    period_ (this),
    alarmType_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void dcalarmType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // acknowledge
      //
      if (n.name () == "acknowledge" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< acknowledge_type > r (
          acknowledge_traits::create (i, f, this));

        if (!this->acknowledge_)
        {
          this->acknowledge_.set (::std::move (r));
          continue;
        }
      }

      // period
      //
      if (n.name () == "period" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!this->period_)
        {
          this->period_.set (period_traits::create (i, f, this));
          continue;
        }
      }

      // alarmType
      //
      if (n.name () == "alarmType" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        if (!alarmType_.present ())
        {
          this->alarmType_.set (alarmType_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }

    if (!alarmType_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "alarmType",
        "http://www.streit.cc/uddf/3.2/");
    }
  }

  dcalarmType* dcalarmType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class dcalarmType (*this, f, c);
  }

  dcalarmType& dcalarmType::
  operator= (const dcalarmType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->acknowledge_ = x.acknowledge_;
      this->period_ = x.period_;
      this->alarmType_ = x.alarmType_;
    }

    return *this;
  }

  dcalarmType::
  ~dcalarmType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const dcalarmType& i)
  {
    if (i.acknowledge ())
    {
      o << ::std::endl << "acknowledge: " << *i.acknowledge ();
    }

    if (i.period ())
    {
      o << ::std::endl << "period: " << *i.period ();
    }

    o << ::std::endl << "alarmType: " << i.alarmType ();
    return o;
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace streit
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

