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

#include "certificationType.hxx"

#include "instructorType.hxx"

#include "encapsulatedDateTimeType.hxx"

namespace streit
{
  // certificationType
  //

  const certificationType::level_optional& certificationType::
  level () const
  {
    return this->level_;
  }

  certificationType::level_optional& certificationType::
  level ()
  {
    return this->level_;
  }

  void certificationType::
  level (const level_type& x)
  {
    this->level_.set (x);
  }

  void certificationType::
  level (const level_optional& x)
  {
    this->level_ = x;
  }

  void certificationType::
  level (::std::unique_ptr< level_type > x)
  {
    this->level_.set (std::move (x));
  }

  const certificationType::specialty_optional& certificationType::
  specialty () const
  {
    return this->specialty_;
  }

  certificationType::specialty_optional& certificationType::
  specialty ()
  {
    return this->specialty_;
  }

  void certificationType::
  specialty (const specialty_type& x)
  {
    this->specialty_.set (x);
  }

  void certificationType::
  specialty (const specialty_optional& x)
  {
    this->specialty_ = x;
  }

  void certificationType::
  specialty (::std::unique_ptr< specialty_type > x)
  {
    this->specialty_.set (std::move (x));
  }

  const certificationType::certificatenumber_optional& certificationType::
  certificatenumber () const
  {
    return this->certificatenumber_;
  }

  certificationType::certificatenumber_optional& certificationType::
  certificatenumber ()
  {
    return this->certificatenumber_;
  }

  void certificationType::
  certificatenumber (const certificatenumber_type& x)
  {
    this->certificatenumber_.set (x);
  }

  void certificationType::
  certificatenumber (const certificatenumber_optional& x)
  {
    this->certificatenumber_ = x;
  }

  void certificationType::
  certificatenumber (::std::unique_ptr< certificatenumber_type > x)
  {
    this->certificatenumber_.set (std::move (x));
  }

  const certificationType::organization_optional& certificationType::
  organization () const
  {
    return this->organization_;
  }

  certificationType::organization_optional& certificationType::
  organization ()
  {
    return this->organization_;
  }

  void certificationType::
  organization (const organization_type& x)
  {
    this->organization_.set (x);
  }

  void certificationType::
  organization (const organization_optional& x)
  {
    this->organization_ = x;
  }

  void certificationType::
  organization (::std::unique_ptr< organization_type > x)
  {
    this->organization_.set (std::move (x));
  }

  const certificationType::instructor_optional& certificationType::
  instructor () const
  {
    return this->instructor_;
  }

  certificationType::instructor_optional& certificationType::
  instructor ()
  {
    return this->instructor_;
  }

  void certificationType::
  instructor (const instructor_type& x)
  {
    this->instructor_.set (x);
  }

  void certificationType::
  instructor (const instructor_optional& x)
  {
    this->instructor_ = x;
  }

  void certificationType::
  instructor (::std::unique_ptr< instructor_type > x)
  {
    this->instructor_.set (std::move (x));
  }

  const certificationType::issuedate_optional& certificationType::
  issuedate () const
  {
    return this->issuedate_;
  }

  certificationType::issuedate_optional& certificationType::
  issuedate ()
  {
    return this->issuedate_;
  }

  void certificationType::
  issuedate (const issuedate_type& x)
  {
    this->issuedate_.set (x);
  }

  void certificationType::
  issuedate (const issuedate_optional& x)
  {
    this->issuedate_ = x;
  }

  void certificationType::
  issuedate (::std::unique_ptr< issuedate_type > x)
  {
    this->issuedate_.set (std::move (x));
  }

  const certificationType::validdate_optional& certificationType::
  validdate () const
  {
    return this->validdate_;
  }

  certificationType::validdate_optional& certificationType::
  validdate ()
  {
    return this->validdate_;
  }

  void certificationType::
  validdate (const validdate_type& x)
  {
    this->validdate_.set (x);
  }

  void certificationType::
  validdate (const validdate_optional& x)
  {
    this->validdate_ = x;
  }

  void certificationType::
  validdate (::std::unique_ptr< validdate_type > x)
  {
    this->validdate_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace streit
{
  // certificationType
  //

  certificationType::
  certificationType ()
  : ::xml_schema::type (),
    level_ (this),
    specialty_ (this),
    certificatenumber_ (this),
    organization_ (this),
    instructor_ (this),
    issuedate_ (this),
    validdate_ (this)
  {
  }

  certificationType::
  certificationType (const certificationType& x,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    level_ (x.level_, f, this),
    specialty_ (x.specialty_, f, this),
    certificatenumber_ (x.certificatenumber_, f, this),
    organization_ (x.organization_, f, this),
    instructor_ (x.instructor_, f, this),
    issuedate_ (x.issuedate_, f, this),
    validdate_ (x.validdate_, f, this)
  {
  }

  certificationType::
  certificationType (const ::xercesc::DOMElement& e,
                     ::xml_schema::flags f,
                     ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    level_ (this),
    specialty_ (this),
    certificatenumber_ (this),
    organization_ (this),
    instructor_ (this),
    issuedate_ (this),
    validdate_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
      this->parse (p, f);
    }
  }

  void certificationType::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // level
      //
      if (n.name () == "level" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< level_type > r (
          level_traits::create (i, f, this));

        if (!this->level_)
        {
          this->level_.set (::std::move (r));
          continue;
        }
      }

      // specialty
      //
      if (n.name () == "specialty" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< specialty_type > r (
          specialty_traits::create (i, f, this));

        if (!this->specialty_)
        {
          this->specialty_.set (::std::move (r));
          continue;
        }
      }

      // certificatenumber
      //
      if (n.name () == "certificatenumber" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< certificatenumber_type > r (
          certificatenumber_traits::create (i, f, this));

        if (!this->certificatenumber_)
        {
          this->certificatenumber_.set (::std::move (r));
          continue;
        }
      }

      // organization
      //
      if (n.name () == "organization" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< organization_type > r (
          organization_traits::create (i, f, this));

        if (!this->organization_)
        {
          this->organization_.set (::std::move (r));
          continue;
        }
      }

      // instructor
      //
      if (n.name () == "instructor" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< instructor_type > r (
          instructor_traits::create (i, f, this));

        if (!this->instructor_)
        {
          this->instructor_.set (::std::move (r));
          continue;
        }
      }

      // issuedate
      //
      if (n.name () == "issuedate" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< issuedate_type > r (
          issuedate_traits::create (i, f, this));

        if (!this->issuedate_)
        {
          this->issuedate_.set (::std::move (r));
          continue;
        }
      }

      // validdate
      //
      if (n.name () == "validdate" && n.namespace_ () == "http://www.streit.cc/uddf/3.2/")
      {
        ::std::unique_ptr< validdate_type > r (
          validdate_traits::create (i, f, this));

        if (!this->validdate_)
        {
          this->validdate_.set (::std::move (r));
          continue;
        }
      }

      break;
    }
  }

  certificationType* certificationType::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class certificationType (*this, f, c);
  }

  certificationType& certificationType::
  operator= (const certificationType& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->level_ = x.level_;
      this->specialty_ = x.specialty_;
      this->certificatenumber_ = x.certificatenumber_;
      this->organization_ = x.organization_;
      this->instructor_ = x.instructor_;
      this->issuedate_ = x.issuedate_;
      this->validdate_ = x.validdate_;
    }

    return *this;
  }

  certificationType::
  ~certificationType ()
  {
  }
}

#include <ostream>

namespace streit
{
  ::std::ostream&
  operator<< (::std::ostream& o, const certificationType& i)
  {
    if (i.level ())
    {
      o << ::std::endl << "level: " << *i.level ();
    }

    if (i.specialty ())
    {
      o << ::std::endl << "specialty: " << *i.specialty ();
    }

    if (i.certificatenumber ())
    {
      o << ::std::endl << "certificatenumber: " << *i.certificatenumber ();
    }

    if (i.organization ())
    {
      o << ::std::endl << "organization: " << *i.organization ();
    }

    if (i.instructor ())
    {
      o << ::std::endl << "instructor: " << *i.instructor ();
    }

    if (i.issuedate ())
    {
      o << ::std::endl << "issuedate: " << *i.issuedate ();
    }

    if (i.validdate ())
    {
      o << ::std::endl << "validdate: " << *i.validdate ();
    }

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

